@echo 清理 VS 垃圾中。。。

Del *.VC.db; *.pdb; *.obj; *.ilk; *.exe; *.log; *.tlog; *.ipch /s
rd markdowneditor.tlog  /s 
rd .vs  /s 
@echo 清理完毕！