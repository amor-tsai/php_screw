# php_screw

## Introduction
Diff from Source:http://sourceforge.net/projects/php-screw/
I add a screw deciphering tool named screwd in the dir "tools".


##简介
转自http://sourceforge.net/projects/php-screw/
本人只是简单添加了一个screw的解密工具,在tools目录下,screwd.

##使用
编译php扩展就不说了,比较简单(本人自己测试在php5.6下可以编译通过,修正了原先旧版本编译不通过的问题).  
在tools目录,make一下,就生成了两个可执行文件screw,screwd.这两个一个是用来加密文件,一个是用来解密文件.  
加密后的文件名是原先的,原先未加密的文件变成了加.screw后缀的文件.  
解密后的文件名在原先文件后加.src后缀  
有任何疑问可以联系我 amor.tsai@gmail.com 


##Introduction 
Translated from http://sourceforge.net/projects/php-screw/ I have simply added a decryption tool for Screw, located in the "tools" directory, named "screwd".

##Usage Compiling the PHP extension goes without saying, it's quite simple (I have personally tested it and it compiles successfully under PHP 5.6, fixing the issues encountered in previous versions).
In the "tools" directory, run the "make" command to generate two executable files, "screw" and "screwd". The former is used for file encryption, while the latter is used for file decryption.
The encrypted files retain their original names, while the previously unencrypted files are transformed into files with the ".screw" extension.
Decrypted files will have the ".src" extension appended to their original names.
If you have any questions, feel free to contact me at amor.tsai@gmail.com.



