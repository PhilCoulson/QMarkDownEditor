@echo 清理 VS 垃圾中。。。
#/q 不确认 /s 所有子目录
Del *.VC.db; *.pdb; *.obj; *.ilk; *.exe; *.log; *.tlog; *.ipch /s
rd markdowneditor.tlog  /s 
rd .vs  /q /s 
rd x64  /q /s 
rd GeneratedFiles /q /s 
rd doc /q /s 
rd debug /q /s 
rd release /q /s 
rd src /q /s 
@echo 清理完毕！