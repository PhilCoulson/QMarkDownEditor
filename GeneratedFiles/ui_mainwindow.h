/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSaveAs;
    QAction *actionNew;
    QAction *actionTiny_Editor;
    QAction *actionMarkDown_Plus;
    QAction *actionCSDN;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *toolBoxPage_0;
    QWidget *toolBoxPage_1;
    QPlainTextEdit *editor;
    QWebEngineView *preview;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_page2;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuEditor;
    QMenu *menuGO;
    QMenu *menuSetting;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionTiny_Editor = new QAction(MainWindow);
        actionTiny_Editor->setObjectName(QStringLiteral("actionTiny_Editor"));
        actionTiny_Editor->setCheckable(true);
        actionTiny_Editor->setChecked(true);
        actionMarkDown_Plus = new QAction(MainWindow);
        actionMarkDown_Plus->setObjectName(QStringLiteral("actionMarkDown_Plus"));
        actionMarkDown_Plus->setCheckable(true);
        actionCSDN = new QAction(MainWindow);
        actionCSDN->setObjectName(QStringLiteral("actionCSDN"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(page);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setAcceptDrops(true);
        toolBoxPage_0 = new QWidget();
        toolBoxPage_0->setObjectName(QStringLiteral("toolBoxPage_0"));
        toolBoxPage_0->setGeometry(QRect(0, 0, 128, 503));
        toolBox->addItem(toolBoxPage_0, QString::fromUtf8("\345\270\270 \347\224\250"));
        toolBoxPage_1 = new QWidget();
        toolBoxPage_1->setObjectName(QStringLiteral("toolBoxPage_1"));
        toolBoxPage_1->setGeometry(QRect(0, 0, 128, 503));
        toolBox->addItem(toolBoxPage_1, QString::fromUtf8("\347\254\224  \350\256\260"));
        splitter->addWidget(toolBox);
        editor = new QPlainTextEdit(splitter);
        editor->setObjectName(QStringLiteral("editor"));
        splitter->addWidget(editor);
        preview = new QWebEngineView(splitter);
        preview->setObjectName(QStringLiteral("preview"));
        preview->setAcceptDrops(true);
        splitter->addWidget(preview);

        horizontalLayout->addWidget(splitter);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setStyleSheet(QStringLiteral(""));
        horizontalLayout_page2 = new QHBoxLayout(page_2);
        horizontalLayout_page2->setSpacing(3);
        horizontalLayout_page2->setObjectName(QStringLiteral("horizontalLayout_page2"));
        horizontalLayout_page2->setContentsMargins(9, 9, 9, 9);
        stackedWidget->addWidget(page_2);

        horizontalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuEditor = new QMenu(menubar);
        menuEditor->setObjectName(QStringLiteral("menuEditor"));
        menuGO = new QMenu(menubar);
        menuGO->setObjectName(QStringLiteral("menuGO"));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuEditor->menuAction());
        menubar->addAction(menuGO->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menu_File->addAction(actionNew);
        menu_File->addAction(actionOpen);
        menu_File->addAction(actionSave);
        menu_File->addAction(actionSaveAs);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);
        menuEditor->addAction(actionTiny_Editor);
        menuEditor->addAction(actionMarkDown_Plus);
        menuGO->addAction(actionCSDN);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MarkDown Editor", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open document", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save current document", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "E&xit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Exit editor", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save &As...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("MainWindow", "Save document under different name", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionNew->setText(QApplication::translate("MainWindow", "&New", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "Create new document", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        actionTiny_Editor->setText(QApplication::translate("MainWindow", "Tiny Editor", Q_NULLPTR));
        actionMarkDown_Plus->setText(QApplication::translate("MainWindow", "MarkDown Plus", Q_NULLPTR));
        actionCSDN->setText(QApplication::translate("MainWindow", "CSDN", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(toolBoxPage_0), QApplication::translate("MainWindow", "\345\270\270 \347\224\250", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(toolBoxPage_1), QApplication::translate("MainWindow", "\347\254\224  \350\256\260", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuEditor->setTitle(QApplication::translate("MainWindow", "Editor", Q_NULLPTR));
        menuGO->setTitle(QApplication::translate("MainWindow", "GO", Q_NULLPTR));
        menuSetting->setTitle(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
