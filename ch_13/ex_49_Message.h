// -----------------------------------------------------------------------------
// File:        ex_49_Message.h
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------

#ifndef EX_49_MESSAGE_H
#define EX_49_MESSAGE_H

#include <set>
#include <string>

class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);
    friend void swap(Folder &, Folder &);

public:
    Message(const std::string &s = "") : contents(s) {}

    Message(const Message &);
    Message &operator=(const Message &);
    Message(Message &&);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

private:
    std::string        contents;
    std::set<Folder *> folders;
    void               addFolder(Folder *);
    void               remFolder(Folder *);

    void add_to_folders(const Message &);
    void remove_from_folders();
    void Message::move_Folders(Message *);
};
void swap(Message &, Message &);

class Folder
{
    friend class Message;
    friend void swap(Folder &, Folder &);

public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();
    void print() const;

private:
    std::set<Message *> messages;
    void                addMsg(Message *);
    void                remMsg(Message *);

    void add_to_messages(const Folder &);
    void remove_from_messages();
};

void swap(Folder &, Folder &);

#endif // EX_49_MESSAGE_H
