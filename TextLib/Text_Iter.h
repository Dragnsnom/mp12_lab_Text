#pragma once
#include "TextNode.h"
#include <fstream>
#include <string>

class TextIter;

class Text {
protected:
    TextNode* root;
public:
    Text(char* s = 0);
    ~Text();

    TextIter GetRoot(); //Создание рут
    TextIter Find(char c); //Поиск буквы. Вернет итератор после найденой буквы
    TextIter Find(char* c); //Поиск. Вернет итератор после найденой буквы
    TextIter FindWord(char* c); //Поиск слова. Вернет итератор после найденого слова


    void Insert(char* c, TextIter i); //Вставить после i
    void Delete(int count, TextIter i); //Удалить начиная с i, цказанное количество букв
    char* Copy(int count, TextIter i); //Копирует указанное количество букв, начиная с i

    friend std::ostream& operator<<(std::ostream& o, Text& t);
};

class TextIter {
protected:
    Text& text;
    TextNode* node;
    TStack<TextNode*> st;
public:
    TextIter(Text& _text, TextNode* _node, TStack<TextNode*> _st);
    TextIter(const TextIter& t);

    bool GoNext(); //Перейти дальше
    bool GoNextChar(); //Перейти к следующей букве
    bool IsEnd(); //Првоерка конца

    void ResetToString();
    void ResetToWord();

    TextNode* Get(); //Получить весь текст
};