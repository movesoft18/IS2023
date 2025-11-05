
#include <iostream>
using namespace std;

class IMessage
{
public:
    virtual void Send() = 0;
    virtual string GetText() = 0;
    virtual string GetSubject() = 0;
    virtual string GetToAddress() = 0;
    virtual string GetFromAddress() = 0;
    virtual void SetText(string t) = 0;
    virtual void SetSubject(string s) = 0;
    virtual void SetToAddress(string a) = 0;
    virtual void SetFromAddress(string a) = 0;
    //virtual void SetVoice(char* byteArray, size_t length) = 0;
    //virtual pair<char*, size_t> GetVoice() = 0;
};

class EmailMessage : public IMessage
{
    string _text;
    string _subject;
    string _fromAddress;
    string _toAddress;
public:
    virtual string GetText() { return _text; }
    virtual string GetSubject() { return _subject; }
    virtual string GetToAddress() { return _toAddress; }
    virtual string GetFromAddress() { return _fromAddress; }
    virtual void SetText(string t) { _text = t; }
    virtual void SetSubject(string s) { _subject = s; }
    virtual void SetToAddress(string a) { _toAddress = a; }
    virtual void SetFromAddress(string a) { _fromAddress = a; }

    void Send()
    {
        cout << "Отправляем Email-сообщение:" << _text << endl;
    }
};

class VoiceMessage : public IMessage
{
    string _text;
    string _subject;
    string _fromAddress;
    string _toAddress;
    char* _voiceArray;
    size_t voiceLength;
public:
    virtual string GetText() { return _text; }
    virtual string GetSubject() { return _subject; }
    virtual string GetToAddress() { return _toAddress; }
    virtual string GetFromAddress() { return _fromAddress; }
    virtual void SetText(string t) { _text = t; }
    virtual void SetSubject(string s) { _subject = s; }
    virtual void SetToAddress(string a) { _toAddress = a; }
    virtual void SetFromAddress(string a) { _fromAddress = a; }

    void Send()
    {
        cout << "Отправляем Email-сообщение:" << _text << endl;
    }
};

class VoiceMessage : public IMessage
{
    string _text;
    string _subject;
    string _fromAddress;
    string _toAddress;
    char* _voiceArray;
    size_t _voiceLength;
public:
    virtual string GetToAddress() { return _toAddress; }
    virtual string GetFromAddress() { return _fromAddress; }
    virtual void SetToAddress(string a) { _toAddress = a; }
    virtual void SetFromAddress(string a) { _fromAddress = a; }
    virtual void SetVoice(char* byteArray, size_t length)
    {
        _voiceArray = byteArray;
        _voiceLength = length;
    }
    virtual pair<char*, size_t> GetVoice() 
    {
        return pair<char*, size_t>(_voiceArray, _voiceLength);
    }

    virtual string GetText() 
    { 
        throw runtime_error("Метод не имеет реализации");
    }
    virtual void SetText(string t) 
    { 
        throw runtime_error("Метод не имеет реализации");
    }

    virtual string GetSubject() 
    { 
        throw runtime_error("Метод не имеет реализации");
    }
    virtual void SetSubject(string s) 
    { 
        throw runtime_error("Метод не имеет реализации");
    }

    void Send()
    {
        cout << "Отправляем голосовое сообщение:" << endl;
    }
};

class IMessage
{
public:
    virtual void Send() = 0;
    virtual string GetToAddress() = 0;
    virtual string GetFromAddress() = 0;
    virtual void SetToAddress(string a) = 0;
    virtual void SetFromAddress(string a) = 0;
};

class IVoiceMessage : public IMessage
{
public:
    virtual void SetVoice(char* byteArray, size_t length) = 0;
    virtual pair<char*, size_t> GetVoice() = 0;
};
class ITextMessage : public IMessage
{
public:
    virtual string GetText() = 0;
    virtual void SetText(string t) = 0;
};

class IEmailMessage : public ITextMessage
{
public:
    virtual string GetSubject() = 0;
    virtual void SetSubject(string s) = 0;
};

class VoiceMessage : public IVoiceMessage
{
    string _fromAddress;
    string _toAddress;
    char* _voiceArray;
    size_t _voiceLength;
public:
    virtual string GetToAddress() { return _toAddress; }
    virtual string GetFromAddress() { return _fromAddress; }
    virtual void SetToAddress(string a) { _toAddress = a; }
    virtual void SetFromAddress(string a) { _fromAddress = a; }
    virtual void SetVoice(char* byteArray, size_t length)
    {
        _voiceArray = byteArray;
        _voiceLength = length;
    }
    virtual pair<char*, size_t> GetVoice()
    {
        return pair<char*, size_t>(_voiceArray, _voiceLength);
    }
    virtual void Send()
    {
        cout << "Отправляем голосовое сообщение:" << endl;
    }
};

class EmailMessage : public IEmailMessage
{
    string _text;
    string _subject;
    string _fromAddress;
    string _toAddress;
public:
    virtual string GetText() { return _text; }
    virtual string GetSubject() { return _subject; }
    virtual string GetToAddress() { return _toAddress; }
    virtual string GetFromAddress() { return _fromAddress; }
    virtual void SetText(string t) { _text = t; }
    virtual void SetSubject(string s) { _subject = s; }
    virtual void SetToAddress(string a) { _toAddress = a; }
    virtual void SetFromAddress(string a) { _fromAddress = a; }

    void Send()
    {
        cout << "Отправляем Email-сообщение:" << _text << endl;
    }
};

class SmsMessage : public ITextMessage
{
    string _text;
    string _fromAddress;
    string _toAddress;
public:
    virtual string GetText() { return _text; }
    virtual string GetToAddress() { return _toAddress; }
    virtual string GetFromAddress() { return _fromAddress; }
    virtual void SetText(string t) { _text = t; }
    virtual void SetToAddress(string a) { _toAddress = a; }
    virtual void SetFromAddress(string a) { _fromAddress = a; }

    void Send()
    {
        cout << "Отправляем sms-сообщение:" << _text << endl;
    }
};

class IPhone
{
public:
    virtual void Call() = 0;
    virtual void TakePhoto() = 0;
    virtual void MakeVideo() = 0;
    virtual void BrowseInternet() = 0;
};

class Phone : public IPhone
{
public:
    void Call()
    {
        cout << "Звоним";
    }

    void TakePhoto()
    {
        cout << "Фотографируем";
    }

    void MakeVideo()
    {
        cout << "Снимаем видео";
    }

    void BrowseInternet()
    {
        cout << "Серфим в интернете";
    }
};

class Photograph
{
public:
    void TakePhoto(Phone phone)
    {
        phone.TakePhoto();
    }
};

class Camera : IPhone
{
public:
    void Call() { }
    void TakePhoto()
    {
        cout << "Фотографируем";
    }
    void MakeVideo() { }
    void BrowseInternet() { }
};

class ICall
{
public:
    virtual void Call() = 0;
};
class IPhoto
{
public:
    virtual void TakePhoto() = 0;
};
class IVideo
{
public:
    virtual void MakeVideo() = 0;
};
class IWeb
{
public:
    virtual void BrowseInternet() = 0;
};

class Camera : public IPhoto
{
public:
    void TakePhoto() override
    {
        cout << "Фотографируем с помощью фотокамеры";
    }
};

class Phone : public ICall, public IPhoto, public IVideo, public IWeb
{
public:
    void Call() override
    {
        cout << "Звоним";
    }
    void TakePhoto() override
    {
        cout << "Фотографируем с помощью смартфона";
    }
    void MakeVideo() override
    {
        cout << "Снимаем видео";
    }
    void BrowseInternet() override
    {
        cout << "Серфим в интернете";
    }
};

class Photograph
{
public:
    void TakePhoto(IPhoto* photoMaker)
    {
        photoMaker->TakePhoto();
    }
};

int main()
{
    Photograph photograph;
    Phone myPhone;
    photograph.TakePhoto(myPhone);
}
