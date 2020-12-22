#include "VigenereCipherMainWindow.h"
#include "ui_VigenereCipherMainWindow.h"

VigenereCipherMainWindow::VigenereCipherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::VigenereCipherMainWindow)
{
    m_ui->setupUi(this);

    fillingInitialData();
    prepareUi();
    prepareConnections();
}

VigenereCipherMainWindow::~VigenereCipherMainWindow()
{
    delete m_ui;
}

void VigenereCipherMainWindow::prepareUi()
{

}

void VigenereCipherMainWindow::prepareConnections()
{
    connect(m_ui->pbEncryptData, SIGNAL (clicked()), this, SLOT (encryptDataSlot()));
    connect(m_ui->pbDecryptData, SIGNAL (clicked()), this, SLOT (decryptDataSlot()));
}

void VigenereCipherMainWindow::fillingInitialData()
{
    m_englishAlphabet = { ' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    m_symbolList = { ' ', '+','!','@','#','$','%','^','&','*','[',']',')','(','=','`',':',';','{','}','.',',','<','>','"','?','/','\''};
}

void VigenereCipherMainWindow::encryptDataSlot()
{
    QChar symbol = m_ui->teOriginalData->toPlainText().at(0);
    QString enCryptedData = QString();
    if (m_englishAlphabet.contains(symbol))
    {
        for (int i = 0; i < m_ui->teOriginalData->toPlainText().count(); i ++)
        {
            QChar symbol = m_ui->teOriginalData->toPlainText().at(i);

            if (m_englishAlphabet.contains(symbol))
            {

                enCryptedData.push_back(m_englishAlphabet.at(m_englishAlphabet.indexOf(symbol) + m_ui->leKey->text().toInt()));
            }
        }
    }
    m_ui->teDecryptedData->setText(enCryptedData);
}

void VigenereCipherMainWindow::decryptDataSlot()
{

}
