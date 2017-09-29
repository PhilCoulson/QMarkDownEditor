@echo 清理 VS 垃圾中。。。

Del *.VC.db; *.pdb; *.obj; *.ilk; *.exe; *.log; *.tlog; /s
rd markdowneditor.tlog /p /s 

@echo 清理完毕！