// -----------------------------------------------------------------------------
// File:        ex_36_37.h
// Author:      Erkam Uzuncayir
// Date:        16/06/2025
// -----------------------------------------------------------------------------

#ifndef EX_36_H
#define EX_36_H
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

#endif // EX_36_H
