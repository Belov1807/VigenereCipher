#include "VigenereCipherMainWindow.h"
#include "ui_VigenereCipherMainWindow.h"

#include <QDateTime>
#include <QClipboard>
#include <QFile>

//#include <QPlastiqueStyle>

VigenereCipherMainWindow::VigenereCipherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::VigenereCipherMainWindow),
    m_key(QString())
{
    m_ui->setupUi(this);
    prepareStyle();

    //QApplication::setStyle(new QPlastiqueStyle());

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
    if (m_ui->teOriginalData->toPlainText() == QString() ||
            m_ui->leKey->text() == QString())
    {
        m_ui->pbEncryptData->setEnabled(false);
        m_ui->pbDecryptData->setEnabled(false);
        m_ui->pbCopyInClipboard->setEnabled(false);
        m_ui->pbClearForm->setEnabled(false);
    }
    else
    {
        m_ui->pbEncryptData->setEnabled(true);
        m_ui->pbDecryptData->setEnabled(true);
        m_ui->pbCopyInClipboard->setEnabled(true);
        m_ui->pbClearForm->setEnabled(true);
    }

//    m_ui->toolBar.s
}

void VigenereCipherMainWindow::prepareConnections()
{
    connect(m_ui->teOriginalData, SIGNAL(textChanged()), this, SLOT(updateFormSlot()));
    connect(m_ui->leKey, SIGNAL(textChanged(const QString &)), this, SLOT(updateFormSlot()));

    connect(m_ui->pbEncryptData, SIGNAL(clicked()), this, SLOT(encryptDataSlot()));
    connect(m_ui->pbDecryptData, SIGNAL(clicked()), this, SLOT(decryptDataSlot()));
    connect(m_ui->pbRandomKey, SIGNAL(clicked()), this, SLOT(generateRandomKeySlot()));
    connect(m_ui->pbCopyInClipboard, SIGNAL(clicked()), this, SLOT(copyInClipboardSlot()));
    connect(m_ui->pbClearForm, SIGNAL(clicked()), this, SLOT(clearFormSlot()));

    connect(m_ui->aExit, SIGNAL(triggered()), this, SLOT(close()));
}

void VigenereCipherMainWindow::updateFormSlot()
{
    prepareUi();
}

void VigenereCipherMainWindow::fillingInitialData()
{
    QList<QChar> capitalEnglishAlphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    QList<QChar> lowerEnglishAlphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    QList<QChar> symbolList = { ' ', '+','!','@','#','$','%','^','&','*','[',']',')','(','=','`',':',';','{','}','.',',','<','>','"','?','/','\''};
    m_allSymbolsList.append(capitalEnglishAlphabet);
    m_allSymbolsList.append(lowerEnglishAlphabet);
    m_allSymbolsList.append(symbolList);
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
    if (m_allSymbolsList.contains(symbol))
    {
        for (int i = 0; i < m_ui->teOriginalData->toPlainText().count(); i ++)
        {
            QChar symbol = m_ui->teOriginalData->toPlainText().at(i);

            if (m_allSymbolsList.contains(symbol))
            {
                int indexSymbolCryptedData = m_allSymbolsList.indexOf(symbol);
                int indexSymbolKey = m_allSymbolsList.indexOf(m_key.at(i));
                int indexEncryptedSymbol = (indexSymbolCryptedData + indexSymbolKey) % m_allSymbolsList.count();

                enCryptedData.push_back(m_allSymbolsList.at(indexEncryptedSymbol));
            }
        }
        m_ui->teDecryptedData->setText(enCryptedData);
    }
    m_ui->lDecryptedDataHeader->setText("Зашифрованные данные");
}

void VigenereCipherMainWindow::decryptDataSlot()
{
    setKey();

    QChar symbol = m_ui->teOriginalData->toPlainText().at(0);
    QString enCryptedData = QString();
    if (m_allSymbolsList.contains(symbol))
    {
        for (int i = 0; i < m_ui->teOriginalData->toPlainText().count(); i ++)
        {
            QChar symbol = m_ui->teOriginalData->toPlainText().at(i);

            if (m_allSymbolsList.contains(symbol))
            {
                int indexSymbolCryptedData = m_allSymbolsList.indexOf(symbol);
                int indexSymbolKey = m_allSymbolsList.indexOf(m_key.at(i));
                int indexEncryptedSymbol = indexSymbolCryptedData - indexSymbolKey;

                if (indexEncryptedSymbol < 0)
                {
                    indexEncryptedSymbol += m_allSymbolsList.count();
                }
                enCryptedData.push_back(m_allSymbolsList.at(indexEncryptedSymbol));
            }
        }
        m_ui->teDecryptedData->setText(enCryptedData);
    }
    m_ui->lDecryptedDataHeader->setText("Расшифрованные данные");
}

void VigenereCipherMainWindow::generateRandomKeySlot()
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
    //Случайный ключ имеет размер от 15 до 20 символов.
    int randomeKeySize = (qrand() % ((20 + 1) - 15) + 15);
    QString randomKey = QString();

    for (int i = 0; i < randomeKeySize; i ++)
    {
        int indexRandomSymbol = (qrand() % ((m_allSymbolsList.count() + 1)));
        QChar randomSymbol = m_allSymbolsList.at(indexRandomSymbol);

        randomKey.append(randomSymbol);
    }
    m_ui->leKey->setText(randomKey);
}

void VigenereCipherMainWindow::copyInClipboardSlot()
{
    QClipboard *clipBoard = QGuiApplication::clipboard();
    clipBoard->setText(m_ui->teDecryptedData->toPlainText());
}

void VigenereCipherMainWindow::clearFormSlot()
{
    m_ui->teOriginalData->clear();
    m_ui->teDecryptedData->clear();
    m_ui->leKey->clear();

    m_key = QString();

    m_ui->lDecryptedDataHeader->setText("Преобразованные данные");
}

void VigenereCipherMainWindow::prepareStyle()
{
    QFile styleFile(":/qss/style");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QString( styleFile.readAll());
    setStyleSheet(styleSheet);
    styleFile.close();

    setWindowIcon(QIcon(":/icons/windowIcon"));

}
