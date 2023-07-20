#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "IR.h"



#include <QIODevice>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->system_init();
    ui->label->setText("串口关闭!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::system_init()
{
    // n 8 1
    this->serial_port.setParity(QSerialPort::NoParity);
    //8位数据
    this->serial_port.setDataBits(QSerialPort::Data8);
    //一位校验位
    this->serial_port.setStopBits(QSerialPort::OneStop);


    connect(&this->serial_port,&QSerialPort::readyRead,this,&MainWindow::recever_data);

}
//recv
void MainWindow::recever_data()
{
    //存储接收到的消息
    QByteArray recv_data=this->serial_port.readAll();
    if(ui->checkBox->checkState() == Qt::Checked)
    {
        //hex
        ui->textEdit->insertPlainText(QString(recv_data.toHex(' ').toUpper().append(' ')));
        QByteArray temp = recv_data;
        //vol+ 被按下
        //获取当前音量值
        int i = vol.GetCurrentVolume();
        if(temp.back() ==  IR_VOL_ADD)
        {
             vol.SetSystemVolume(i+=5);
            if(i>100)
            {
                i = 0;
            }
        }
        i = vol.GetCurrentVolume();
        if(temp.back() ==  IR_VOL_MINUS)
        {
            vol.SetSystemVolume(i-=5);
            if(i<0)
            {
                i=0;
            }
        }
    }
    else
    {
        //dec
        ui->textEdit->insertPlainText(QString(recv_data));
    }


}

//send
void MainWindow::on_pushButton_clicked()
{
    QString send_data = ui->lineEdit->text();
    if(ui->checkBox->checkState() == Qt::Checked)
    {

        QByteArray sendBuf = QByteArray::fromHex(send_data.toLatin1());

        this->serial_port.write(sendBuf);
        qDebug()<<sendBuf;

    }
    else
    {
        QByteArray send_array = send_data.toLatin1();
        this->serial_port.write(send_array);
    }
}

//检索系统串口信息
void MainWindow::on_pushButton_2_clicked()
{
    ui->comboBox->clear();
    foreach(const QSerialPortInfo & info,QSerialPortInfo::availablePorts())
    {
        ui->comboBox->addItem(info.portName());
    }
}

//关闭串口
void MainWindow::on_pushButton_4_clicked()
{
    this->serial_port.close();
    ui->label->setText("串口关闭");

}

//打开串口
void MainWindow::on_pushButton_3_clicked()
{
    this->serial_port.setPortName(ui->comboBox->currentText());
    qDebug()<<ui->comboBox->currentText();
    //this->serial_port.setBaudRate(QSerialPort::Baud9600);
    //ZZthis->serial_port.setBaudRate(QSerialPort::Baud115200);
    this->serial_port.setBaudRate(ui->comboBox_2->currentText().toInt());//波特率

    if(!this->serial_port.open(QIODevice::ReadWrite))  //以读写模式打开
    {
        QMessageBox::warning(this,"警告","串口打开错误");
        return;
    }
    else
    {
        QMessageBox::information(this,"操作成功","打开串口成功");
    }
    ui->label->setText("串口已打开");

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->clear();
}



void MainWindow::on_textEdit_textChanged()
{

}

