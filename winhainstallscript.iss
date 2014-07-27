[Setup]
AppName=Winha Live
AppVerName=0.0.1
DefaultDirName={pf}\Winha Live
DefaultGroupName=Winha Live
Compression=lzma
SolidCompression=yes
UninstallDisplayIcon=vamk.ico
AppCopyright=Copyright (C) Olufowobi Lawal
OutputDir=C:\Users\simulate\Desktop

[Files]
Source: WinhaProject.exe; DestDir: {app}
Source: libeay32.dll; DestDir: {app}
Source: libgcc_s_dw2-1.dll; DestDir: {app}
Source: mingwm10.dll; DestDir: {app}
Source: phonon4.dll; DestDir: {app}
Source: QtCore4.dll; DestDir: {app}
Source: QtGui4.dll; DestDir: {app}
Source: QtNetwork4.dll; DestDir: {app}
Source: QtWebKit4.dll; DestDir: {app}
Source: QtXml4.dll; DestDir: {app}
Source: ssleay32.dll; DestDir: {app}
Source: vamk.ico; DestDir: {app}
Source: readme.txt; DestDir: {app}; Flags: isreadme

[Icons]
Name: {group}\WinhaProject; Filename: {app}\WinhaProject.exe; IconFilename: {app}\vamk.ico
Name: {group}\Uninstall WinhaProject; Filename: {uninstallexe}


;[Tasks]
;Name: desktopicon; Description: "Create a &desktop icon"; GroupDescription: "Additional :";
;Name: quicklaunchicon; Description: "Create a &Quick Launch icon"; GroupDescription: "Additional :";  Flags: unchecked

[Run]

Filename: {app}\WinhaProject.exe; Description: Launch application; Flags: postinstall nowait skipifsilent unchecked
