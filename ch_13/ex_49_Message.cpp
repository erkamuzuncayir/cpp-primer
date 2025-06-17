// -----------------------------------------------------------------------------
// File:        ex_49_Message.cpp
// Author:      Erkam Uzuncayir
// Date:        16/06/2025
// -----------------------------------------------------------------------------

#include "ex_49_Message.h"
#include <iostream>
#include <set>

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) { add_to_folders(m); }

Message &Message::operator=(const Message &rhs)
{
    remove_from_folders();
    contents = rhs.contents;
    folders  = rhs.folders;
    add_to_folders(rhs);
    return *this;
}
Message::Message(Message &&rhs) : contents(std::move(rhs.contents))
{
    move_Folders(&rhs);
}

Message::~Message() { remove_from_folders(); }

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFolder(Folder *fp) { folders.insert(fp); }

void Message::remFolder(Folder *fp) { folders.erase(fp); }

void Message::add_to_folders(const Message &m)
{
    for (auto &fp : m.folders)
        fp->addMsg(this);
}

void Message::remove_from_folders()
{
    for (auto &fp : folders)
        fp->remMsg(this);
    folders.clear();
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_folders();
    rhs.remove_from_folders();

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    lhs.add_to_folders(lhs);
    rhs.add_to_folders(rhs);
}

Folder::Folder(const Folder &rhs) : messages(rhs.messages) { add_to_messages(rhs); }

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_messages();
    messages = rhs.messages;
    add_to_messages(rhs);
    return *this;
}

void Folder::add_to_messages(const Folder &f)
{
    for (auto &mp : f.messages)
    {
        mp->addFolder(this);
    }
}

void Folder::remove_from_messages()
{
    for (auto &mp : messages)
        mp->remFolder(this);
    messages.clear();
}

Folder::~Folder() { remove_from_messages(); }
void Folder::print() const
{
    for (auto &mp : messages)
        std::cout << mp->contents << std::endl;
}

void Folder::addMsg(Message *mp) { messages.insert(mp); }

void Folder::remMsg(Message *mp) { messages.erase(mp); }

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;

    for (auto mp : lhs.messages)
        mp->remFolder(&lhs);
    for (auto mp : rhs.messages)
        mp->remFolder(&rhs);

    swap(lhs.messages, rhs.messages);

    for (auto mp : lhs.messages)
        mp->addFolder(&lhs);
    for (auto mp : rhs.messages)
        mp->addFolder(&rhs);
}

int main()
{
    Folder  f_1, f_2, f_3;
    Message m_1("Hello"), m_2("World"), m_3("Kool");

    m_1.save(f_1);
    m_2.save(f_2);
    m_3.save(f_3);

    std::cout << "Before swap\n";
    f_1.print();
    f_2.print();
    f_3.print();

    swap(f_1, f_2);
    swap(f_3, f_1);

    std::cout << "After swap\n";
    f_1.print();
    f_2.print();
    f_3.print();

    return 0;
}
