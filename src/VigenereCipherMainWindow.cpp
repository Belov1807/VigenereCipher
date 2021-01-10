#include "VigenereCipherMainWindow.h"
#include "ui_VigenereCipherMainWindow.h"

VigenereCipherMainWindow::VigenereCipherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::VigenereCipherMainWindow),
    m_key(QString())
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
    m_englishAlphabet = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
}

void VigenereCipherMainWindow::setKey()
{
    m_key = QString();
    QString inputKey = m_ui->leKey->text();

    int j = 0;

    for (int i = 0; i < m_ui->teOriginalData->toPlainText().count(); i ++)
    {

        if (j == inputKey.count())
        {
            j = 0;
        }

        m_key.append(inputKey.at(j));
        j ++;
    }

}

void VigenereCipherMainWindow::encryptDataSlot()
{   
    setKey();

    QChar symbol = m_ui->teOriginalData->toPlainText().at(0);
    QString enCryptedData = QString();
    if (m_englishAlphabet.contains(symbol))
    {
        for (int i = 0; i < m_ui->teOriginalData->toPlainText().count(); i ++)
        {
            QChar symbol = m_ui->teOriginalData->toPlainText().at(i);

            if (m_englishAlphabet.contains(symbol))
            {
                int indexSymbolCryptedData = m_englishAlphabet.indexOf(symbol);
                int indexSymbolKey = m_englishAlphabet.indexOf(m_key.at(i));
                int indexEncryptedSymbol = (indexSymbolCryptedData + indexSymbolKey) % m_englishAlphabet.count();

                enCryptedData.push_back(m_englishAlphabet.at(indexEncryptedSymbol));
            }
        }
        m_ui->teDecryptedData->setText(enCryptedData);
    }
}

void VigenereCipherMainWindow::decryptDataSlot()
{

}
