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

    /*!
     * \brief Сгенерировать случайный ключ.
     */
    void generateRandomKeySlot();

    /*!
     * \brief Копировать в буффер обмена.
     */
    void copyInClipboardSlot();

    /*!
     * \brief Очистить форму.
     */
    void clearFormSlot();

    /*!
     * \brief Обновляет состояние формы.
     */
    void updateFormSlot();

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
     * \brief Устанавливает ключ.
     */
    void setKey();

    /*!
     * \brief Графический интерфейс.
     */
    Ui::VigenereCipherMainWindow *m_ui;

    /*!
     * \brief Список всех символов.
     */
    QList<QChar> m_allSymbolsList;

    /*!
     * \brief ключ.
     */
    QString m_key;

};
#endif // VIGENERECIPHERMAINWINDOW_H
