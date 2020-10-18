#include "VigenereCipherMainWindow.h"
#include "ui_VigenereCipherMainWindow.h"

VigenereCipherMainWindow::VigenereCipherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::VigenereCipherMainWindow)
{
    m_ui->setupUi(this);
}

VigenereCipherMainWindow::~VigenereCipherMainWindow()
{
    delete m_ui;
}

