#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    numShades = 2;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Load Image Button
void MainWindow::on_pushButton_clicked()
{
    //Dialog for user to choose an image file
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.xpm *.jpg)"),0,QFileDialog::DontUseNativeDialog);

    imageObject = new QImage();
    imageObject->load(filename);
    image = QPixmap::fromImage(*imageObject);
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());

    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    //Initialize OpenCV Handler
    cvHandler = new OpenCVHandler(filename.toStdString());
}

void MainWindow::on_pushButton_2_clicked()
{
    cvHandler->averageGS();
}

void MainWindow::on_pushButton_3_clicked()
{
    cvHandler->lightnessGS();
}

void MainWindow::on_pushButton_4_clicked()
{
    cvHandler->luminosityGS();
}

void MainWindow::on_pushButton_5_clicked()
{
    cvHandler->decompMinGS();
}

void MainWindow::on_pushButton_6_clicked()
{
    cvHandler->decompMaxGS();
}

void MainWindow::on_pushButton_7_clicked()
{
    cvHandler->redChannelGS();
}

void MainWindow::on_pushButton_8_clicked()
{
    cvHandler->greenChannelGS();
}

void MainWindow::on_pushButton_9_clicked()
{
    cvHandler->blueChannelGS();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    numShades = value;
    ui->lcdNumber->display(value);

}

void MainWindow::on_pushButton_10_clicked()
{
    cvHandler->shadesOfGrayGS(numShades);
}


