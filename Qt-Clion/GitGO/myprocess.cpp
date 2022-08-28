#include "myprocess.h"
#include "ui_myprocess.h"
#include <QDebug>

MyProcess::MyProcess(QWidget *parent)
        : QWidget(parent), ui(new Ui::MyProcess) {
    ui->setupUi(this);

    pro = new QProcess(this);
    //pro = new QProcess;
    //newthread = new NewThread(this);
}

MyProcess::~MyProcess() {
    delete ui;
}

//开始
void MyProcess::on_pushButton_start_clicked() {
    //**************************************进程
    //如果进程未运行,启动
    if (pro->state() == QProcess::NotRunning) {
//        QString cmd = QString("\"D:/QQ/Bin/QQ.exe\"");//这是我电脑的qq启动程序
//        QString cmd = QString("\"cmd\"");
/*
 * 为什么有些时候调用不了电脑的其他软件,调用进程
 *
 * */
        QString cmd = QString("D:/fastgithub_win-x64/FastGithub.UI.exe");
//        pro->start(cmd);  //win下进程调用的命令行也不一样
/*  https://www.qt.io/blog/2017/08/25/a-new-qprocessstartdetached  官方解释*/

/*
 * From Qt 5.10 on, there is a new way how to start detached processes with QProcess.

Of course you know this, but let me quickly repeat what a detached process is.  If you start a program using QProcess without detaching, then the destructor of QProcess will terminate the process.  In contrast, a detached process keeps running unaffected when the calling process exits.  On Unix, a detached process will run in its own session and act like a daemon.

Traditionally, we start detached processes with the static QProcess::startDetached() method.

QProcess::startDetached("aplay tada.wav");

There is a second overload that supports passing a separate argument list and the working directory.  It also lets us retrieve the PID of the started process.

qint64 pid;
QProcess::startDetached("mpg123", {"Jeopardy_Theme.mp3"}, musicDirPath, &pid);
printf("Performing a lengthy calculation...");
calculateDeterminant(reallyBigMatrix);
puts("done.");
QProcess::startDetached("kill", {QString::number(pid)});

This little example crunches numbers for a while and plays the Jeopardy Theme to entertain the user.  When the calculation result is ready, it kills the music player using the obtained PID.

When running this example on Linux, you will notice a little annoyance: we have no way of suppressing the output of the detached process.
(Okay, this particular tool has the "--quiet" option, but let's ignore that for the example's sake.)

Qt Users have requested for a long long time the ability to

set the process environment,
redirect stdin, stdout, stderr to files
and set native arguments and the CreateProcess argument modifier on Windows
for detached processes.

All this is now possible in Qt 5.10!  But instead of adding a monstrous overload for the static startDetached() method, we added a non-static QProcess::startDetached(qint64 *pid).  This new member function reads the properties of your QProcess object and starts the to-be-detached process accordingly.  It can be used as follows:

QProcess process;
process.setProgram("mpg123");
process.setArguments({"Jeopardy_Theme.mp3"});
process.setWorkingDirectory(musicDirPath);
process.setStandardOutputFile(QProcess::nullDevice());
process.setStandardErrorFile(QProcess::nullDevice());
qint64 pid;
process.startDetached(&pid);
...

The redirection to /dev/null makes sure that the user is not disturbed by visual output of the audio player.

Only a certain sensible subset of functions is supported for startDetached():

setArguments()
setCreateProcessArgumentsModifier()
setNativeArguments()
setProcessEnvironment()
setProgram()
setStandardErrorFile()
setStandardInputFile()
setStandardOutputFile()
setWorkingDirectory()
All other properties of the QProcess object are ignored.

If there are more properties to be supported in the future, they can be easily added in the implementation of the new startDetached().

Happy detaching!

 */
        pro->startDetached(cmd);  //
        QThread::sleep(2);
        qDebug() << "Go";
//        Wnd = FindWindow(NULL, L"FastGithub.UI.exe");
        //launger是调用启动进程的进程，调用后把自己销毁了
    }
    //**************************************
}

//停止
void MyProcess::on_pushButton_stop_clicked() {
    pro->kill();
    //等待结束
    pro->waitForFinished();
}

