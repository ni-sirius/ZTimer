#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QIcon>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //QResource::registerResource("/path/to/myresource.rcc");

    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setVisible(false);


    _icon = new QSystemTrayIcon(QIcon(":/icons/icon.png"), this);
    connect(_icon, &QSystemTrayIcon::activated, [this](QSystemTrayIcon::ActivationReason reason){
        if (reason == QSystemTrayIcon::Trigger)
        {
            //QMessageBox msgBox;
            //msgBox.setText("The document has been modified.");
            //msgBox.exec();

            this->setVisible(false);
        }
        if (reason == QSystemTrayIcon::Context)
        {
            this->setVisible(true);
        }
    });


    QMenu menu;
    menu.addAction("Action");

    _icon->setContextMenu(&menu);
    _icon->show();

    connect(ui->pushButton, &QPushButton::clicked, [this]{
       _icon->showMessage("Hekko", "World");
    });

    ui->label_2->setPixmap(QPixmap("F:\Code\ZnakTimer\Penguins.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
