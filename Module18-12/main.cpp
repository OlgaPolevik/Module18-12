//
//  main.cpp
//  Module18-12
//
//  Created by Ольга Полевик on 06.10.2021.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class User
{
    string _name;
    string _login;
    string _pass;

public:
    //User(string name, string login, string pass):_name(name), _login(login), _pass(pass) {}
    User() = default;
    
    void setname(const string& name)
    {
        _name = name;
    }
    const string& getname() const
    {
        return _name;
    }
    
    void setlogin(const string& login)
    {
        _login = login;
    }
    const string& getlogin() const
    {
        return _login;
    }
    
    void setpass(const string& pass)
    {
        _pass = pass;
    }
    const string& getpass() const
    {
        return _pass;
    }
    
    
    
    friend fstream& operator >>(fstream& is, User& obj);
    friend ostream& operator <<(ostream& os, const User& obj);
};

class Message
{
    string _text;
    string _sender;
    string _receiver;

public:
   Message (string text, string sender, string receiver):_text(text), _sender(sender), _receiver(receiver) {}
    Message() = default;
    
    void settext(const string& text)
    {
        _text = text;
    }
    const string& gettext() const
    {
        return _text;
    }
    
    void setsender(const string& sender)
    {
        _sender = sender;
    }
    const string& getsender() const
    {
        return _sender;
    }
    
    void setreceiver(const string& receiver)
    {
        _receiver = receiver;
    }
    const string& getreceiver() const
    {
        return _receiver;
    }
    
    
    friend fstream& operator >>(fstream& is, Message& obj);
    friend ostream& operator <<(ostream& os, const Message& obj);
};


fstream& operator >>(fstream& is, User& obj)
{
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}
ostream& operator <<(ostream& os, const User& obj)
{
    os << obj._name;
    os << ' ';
    os << obj._login;
    os << ' ';
    os << obj._pass;
    return os;
}

fstream& operator >>(fstream& is, Message& obj)
{
    is >> obj._text;
    is >> obj._sender;
    is >> obj._receiver;
    return is;
}
ostream& operator <<(ostream& os, const Message& obj)
{
    os << obj._text;
    os << ' ';
    os << obj._sender;
    os << ' ';
    os << obj._receiver;
    return os;
}

int main()
{
    User u_obj;
    
    fstream user_file_load( "users.txt" );
    if (!user_file_load)
    {
        user_file_load = fstream("users.txt", ios::in | ios::out | ios::trunc);
        cout << "Data empty" << endl;
    }
    if(!user_file_load.is_open())
    {
        cout << "Could not open input file!" << '\n';
        return 1;
    }
    user_file_load >> u_obj;
    cout << u_obj << endl;
    user_file_load.close();
    system("chmod 600 users.txt");
    
    fstream user_file_write( "users.txt");
    if (!user_file_write)
    {
        user_file_write = fstream("users.txt", ios::in | ios::out | ios::trunc);
    }
    if(!user_file_write.is_open())
    {
        cout << "Could not open input file!" << '\n';
        return 1;
    }
    u_obj.setname("user3");
    u_obj.setlogin("login3");
    u_obj.setpass("pass3");
    user_file_write << u_obj << endl;
    user_file_write.close();
    system("chmod 600 users.txt");
    
    fstream user_file_read( "users.txt" );
    if (!user_file_read)
    {
        user_file_read = fstream("users.txt", ios::in | ios::out | ios::trunc);
    }
    if(!user_file_read.is_open())
    {
        cout << "Could not open input file!" << '\n';
        return 1;
    }
 
    user_file_read >> u_obj;
    cout << u_obj << endl;
    user_file_read.close();
    system("chmod 600 users.txt");
    
    Message m_obj;
    
    fstream message_file_load( "messages.txt" );
    if (!message_file_load)
    {
        message_file_load = fstream("messages.txt", ios::in | ios::out | ios::trunc);
        cout << "Data empty" << endl;
    }
    if(!message_file_load.is_open())
    {
        cout << "Could not open input file!" << '\n';
        return 1;
    }
    message_file_load >> m_obj;
    cout << m_obj << endl;
    message_file_load.close();
    system("chmod 600 messages.txt");
    
    fstream message_file_write( "messages.txt");
    if (!message_file_write)
    {
        message_file_write = fstream("messages.txt", ios::in | ios::out | ios::trunc);
    }
    if(!message_file_write.is_open())
    {
        cout << "Could not open input file!" << '\n';
        return 1;
    }
    m_obj.settext("111");
    m_obj.setsender("user2");
    m_obj.setreceiver("user1");
    message_file_write << m_obj << endl;
    message_file_write.close();
    system("chmod 600 messages.txt");
   
    fstream message_file_read( "messages.txt" );
    if (!message_file_read)
    {
        message_file_read = fstream("messages.txt", ios::in | ios::out | ios::trunc);
    }
    if(!message_file_read.is_open())
    {
        cout << "Could not open input file!" << '\n';
        return 1;
    }
    message_file_read >> m_obj;
    cout << m_obj << endl;
    message_file_read.close();
    system("chmod 600 messages.txt");
    
    return 0;
}
    
