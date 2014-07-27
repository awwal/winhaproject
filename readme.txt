
Author: Olufowobi Lawal , talktolawal@gmail.com

********************************************
This program scrapes the Vamk students pages for 
information needed by student on a regular basis, 
email, result and calendar in a simpler, easy format. 
Tested on ubuntu10.10 
********************************************

With Windows
*******************************************
Known Issue
Problem with QSslSocket on windows. 
Some dll are required.
Instructions Below
*******************************************


http://codeblog.vurdalakov.net/2009/11/solution-qsslsocket-cannot-call.html

Open Win32 OpenSSL Installation Project page.
Download the latest "light" Win32 or Win64 installation package, for example "Win32 OpenSSL v0.9.8l Light".
Install it to any location. Ignore "Microsoft Visual C++ 2008 Redistributables" warning (click OK) and select copying OpenSSL DLLs to "The OpenSSL binaries (\bin) directory".
Copy libeay32.dll and ssleay32.dll from the \bin folder to the same place where your QtNetwork4.dll or QtNetworkd4.dll is located.

(Note! this two dlls are in the win32lib folder)
*****************************************

