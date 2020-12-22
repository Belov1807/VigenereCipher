#ifndef VIGENERECIPHERMAINWINDOW_H
#define VIGENERECIPHERMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class VigenereCipherMainWindow;
}
QT_END_NAMESPACE

/*!
 * \brief Класс главного окна приложения.
 */
class VigenereCipherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param parent - родительский виджет.
     */
    VigenereCipherMainWindow(QWidget *parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~VigenereCipherMainWindow();

private slots:
    /*!
     * \brief Зашифровать данные.
     */
    void encryptDataSlot();
    /*!
     * \brief Расшифровать данные.
     */
    void decryptDataSlot();

private:
    /*!
     * \brief Заполнение исходных данных
     */
    void fillingInitialData();
    /*!
     * \brief Настравивает отображение.
     */
    void prepareUi();
    /*!
     * \brief Подготавливает соеденения.
     */
    void prepareConnections();

    /*!
     * \brief Графический интерфейс.
     */
    Ui::VigenereCipherMainWindow *m_ui;

    /*!
     * \brief Русский алфавит.
     */
    QList<char> m_russianAlphabet;
    /*!
     * \brief Английский алфавит.
     */
    QList<QChar> m_englishAlphabet;
    /*!
     * \brief Список символов.
     */
    QList<char> m_symbolList;

};
#endif // VIGENERECIPHERMAINWINDOW_H
