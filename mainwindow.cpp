/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "previewpage.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QFontDatabase>
#include <QMessageBox>
#include <QTextStream>
#include <QWebChannel>
#include <QWebenginePage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
	m_pWebView(nullptr),
	m_pCSDNWebView(nullptr),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->editor->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
   // ui->preview->setContextMenuPolicy(Qt::NoContextMenu);

    PreviewPage *page = new PreviewPage(this);
    ui->preview->setPage(page);
	
	m_csdnUrl.setUrl(QString("http://write.blog.csdn.net/postlist"));

    connect(ui->editor, &QPlainTextEdit::textChanged,
            [this]() { m_content.setText(ui->editor->toPlainText()); });

    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject(QStringLiteral("content"), &m_content);
    page->setWebChannel(channel);

    ui->preview->setUrl(QUrl("qrc:/index.html"));

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onFileNew);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onFileOpen);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onFileSave);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::onFileSaveAs);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::onExit);

    connect(ui->editor->document(), &QTextDocument::modificationChanged,
            ui->actionSave, &QAction::setEnabled);

	connect(ui->actionCSDN,&QAction::triggered, this, &MainWindow::onOpenCSDN);
	// connect editor changed slots
	m_pWebView = new QWebEngineView(this);
	m_pWebView->setPage(new QWebEnginePage(this));
	ui->stackedWidget->insertWidget(1, m_pWebView);
	connect(ui->actionMarkDown_Plus,SIGNAL(toggled(bool)), this, SLOT(onMarkDownPlusChecked(bool)));
	connect(ui->actionTiny_Editor, SIGNAL(toggled(bool)), this, SLOT(onTinyEditorChecked(bool)));
    QFile defaultTextFile(":/default.md");
    defaultTextFile.open(QIODevice::ReadOnly);
    ui->editor->setPlainText(defaultTextFile.readAll());
}

MainWindow::~MainWindow()
{
    delete ui;

	if (nullptr == m_pCSDNWebView)
	{
		delete m_pCSDNWebView;
		m_pCSDNWebView = nullptr;
	}
}

void MainWindow::openFile(const QString &path)
{
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, windowTitle(),
                             tr("Could not open file %1: %2").arg(
                                 QDir::toNativeSeparators(path), f.errorString()));
        return;
    }
    m_filePath = path;
    ui->editor->setPlainText(f.readAll());
}

bool MainWindow::isModified() const
{
    return ui->editor->document()->isModified();
}

void MainWindow::onFileNew()
{
    if (isModified()) {
        QMessageBox::StandardButton button = QMessageBox::question(this, windowTitle(),
                             tr("You have unsaved changes. Do you want to create a new document anyway?"));
        if (button != QMessageBox::Yes)
            return;
    }

    m_filePath.clear();
    ui->editor->setPlainText(tr("## New document"));
    ui->editor->document()->setModified(false);
}

void MainWindow::onFileOpen()
{
    if (isModified()) {
        QMessageBox::StandardButton button = QMessageBox::question(this, windowTitle(),
                             tr("You have unsaved changes. Do you want to open a new document anyway?"));
        if (button != QMessageBox::Yes)
            return;
    }

    QString path = QFileDialog::getOpenFileName(this,
        tr("Open MarkDown File"), "", tr("MarkDown File (*.md)"));
    if (path.isEmpty())
        return;

    openFile(path);
}

void MainWindow::onFileSave()
{
    if (m_filePath.isEmpty()) {
        onFileSaveAs();
        return;
    }

    QFile f(m_filePath);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text))  {
        QMessageBox::warning(this, windowTitle(),
                             tr("Could not write to file %1: %2").arg(
                                 QDir::toNativeSeparators(m_filePath), f.errorString()));
        return;
    }
    QTextStream out(&f);
	out.setCodec("UTF-8");//输出时要设置编码格式，否则可能出现中文字符乱码现象。
	out << ui->editor->toPlainText();

    ui->editor->document()->setModified(false);
}

void MainWindow::onFileSaveAs()
{
	QString str_DateTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString path = QFileDialog::getSaveFileName(this,
        tr("Save MarkDown File"), str_DateTime, tr("MarkDown File (*.md ,*.markdown)"));//注意selectFilter的文件名要跟后面的逗号空格分开，碰到了后面的逗号被作为文件名的问题
    if (path.isEmpty())
        return;
    m_filePath = path;
    onFileSave();
}

void MainWindow::onExit()
{
    if (isModified()) {
        QMessageBox::StandardButton button = QMessageBox::question(this, windowTitle(),
                             tr("You have unsaved changes. Do you want to exit anyway?"));
        if (button != QMessageBox::Yes)
            return;
    }
    close();
}

void MainWindow::onMarkDownPlusChecked(bool checked)
{
	if (checked)
	{
		ui->stackedWidget->setCurrentIndex(1);//1 is the markdownplus Editor 's page number.
		m_pWebView->load(QUrl("D:/project/markdown-plus/markdowneditor/resources/markDownPlus/dist/index.html"));
	}
}

void MainWindow::onTinyEditorChecked(bool checked)
{
	if (checked)
	{
		ui->stackedWidget->setCurrentIndex(0);//0 is the Tiny Editor 's page number.
		//ui->wid_web2->load(QUrl("qrc:/index.html"));
	}
}

void MainWindow::onOpenCSDN()
{
	
//if changed ,ask user to save the file.
	int page = ui->stackedWidget->currentIndex();
	switch(page)//for dif page 
	{
	case 0:
		//文件修改保存文件
		if (isModified())
		{
			onFileSaveAs();
		}
		if (nullptr == m_pCSDNWebView)
		{
			m_pCSDNWebView = new QWebEngineView(this);
			m_pCSDNWebView->setPage(new QWebEnginePage(this));
			m_pCSDNWebView->setAttribute(Qt::WA_InputMethodEnabled,true);
		}
		ui->stackedWidget->insertWidget(2,m_pCSDNWebView);
		ui->stackedWidget->setCurrentIndex(2);
		if (nullptr != m_pCSDNWebView)
		{
			m_pCSDNWebView->load(m_csdnUrl);
			qDebug() << m_csdnUrl << endl;
		}
		break;
	case 1:
		break;
	default:
		break;

	}
//save file edit

//turn current editor page to the CSDN blog web page.

}
