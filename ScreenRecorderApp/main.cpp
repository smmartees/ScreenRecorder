/*
 * Sam Pelot
 * January 6th, 2026
 * Screen Recorder app
 */

#include <QApplication>
#include "appManager.cpp"

int main(int argc, char *argv[])
{
    QApplication myScreenRecordingApp(argc, argv);

    AppManager manager; // creates the window

    manager.showWindow();   // show the window

    return myScreenRecordingApp.exec(); // runs the program for more than a flash
                                        // return instance .exec()
}

/*#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("ScreenRecorderApp", "Main");

    return app.exec();
}
*/
