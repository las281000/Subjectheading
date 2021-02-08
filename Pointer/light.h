#ifndef LIGHT_H
#define LIGHT_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class Light : public QSyntaxHighlighter
{
    Q_OBJECT
    using BaseClass = QSyntaxHighlighter;
public:
    explicit Light(QTextDocument* parent = nullptr);

    void searchStr(const QString& str);

protected:
    void highlightBlock(const QString &text) override;

private:
    QRegularExpression m_pattern; // Регулярное выражение для поиска, в нашем случае это слово или текст
    QTextCharFormat m_format;     // Форматирование текста, подсветка
    int t; //количество совпадений

signals:
    void setMessageText(int);
};

#endif // SEARCHHIGHLIGHT_H
