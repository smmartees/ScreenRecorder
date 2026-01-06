/*
 * Sam Pelot
 * January 6th, 2026
 * Screen Recorder app
 */

// window creation
#include <QMainWindow>
#include <QWidget>  // included by default
#include <QVBoxLayout>  // vertical box layout
// button creation/manipulation
#include <QLabel>   // allows for displaying text like the app name
#include <QPushButton>  // actually allows buttons
// file dialogue
#include <QFileDialog>  // can browse to any location on computer to save the screen recording


class AppManager{
public:
    AppManager(){
        setupUI();
    }

    void showWindow(){
        mainWindow->show(); // displays the main window
    }

private:
    QMainWindow *mainWindow;
    QWidget *centralWidget; // all the other widgets will be inisde the central widget
    QVBoxLayout *mainLayout;
    QLabel *titleLable;
    QPushButton *recButton;
    QString outputFilePath; // was a pointer originally, but there was an error in the QFileDialog line
                            // solution was to either remove the star here or put one infrono of the outputFilePath variable in the QObject

    // creating the window
    void setupUI() {
        mainWindow = new QMainWindow;
        mainWindow->setWindowTitle("My Screen Recording App");
        mainWindow->resize(400,300);

        centralWidget = new QWidget;
        // create main layout instance, passing the central widget because it will be part of the main layout
        mainLayout = new QVBoxLayout(centralWidget);    // and all of the main GUI content/ all the primary GUI widgets
                                                        // will be inside of the central widget
                                                        // any widgets put inside of the central widget will obey the mainLayout

        titleLable = new QLabel("Screen Record");
        titleLable->setAlignment(Qt::AlignCenter);
        titleLable->setStyleSheet("font-size:22px; color:blue");
        mainLayout->addWidget(titleLable);

        recButton = new QPushButton("Record");
        recButton->setStyleSheet("font-size:32px; color:black; background-color:green");
        mainLayout->addWidget(recButton);

        QObject::connect(recButton, &QPushButton::clicked,[this](){
            if(recButton->text()=="Record") {
                // first argument is the window on which the dialog will appear
                // second arg is where the recording to be saved. Leaving blank for a default of current working directory
                // third arg is the type of files a user can see through the dialog box & extension to save over
                outputFilePath = QFileDialog::getSaveFileName(mainWindow, "Save Recording", "", "Video Files (*.mp4)");

                if(!outputFilePath.isEmpty()){
                    //next part
                }
            }
        });


        // this sets the central widget to obey the main layout
        centralWidget->setLayout(mainLayout);

        mainWindow->setCentralWidget(centralWidget);
    }
};
