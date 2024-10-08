#ifndef CONTACT_HPP
#define CONTACT_HPP

#include<string>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_num;
        std::string darck_secret;
    public:
        Contact()
        {
            this.first_name = "Unknown";
            this.last_name = "Unknown";
            this.nick_name = "Unknown";
            this.phone_num = "Unknown";
            this.darck_secret = "Unknown";
        }
        std::string getFirst_name const()
        {
            return first_name;
        }
        std::string getLast_name const()
        {
            return Last_name;
        }
        std::string getNick_name const()
        {
            return nick_name;
        }
        std::string getPhone_num const()
        {
            return phone_num;
        }
        std::string getDarck_secret const()
        {
            return darck_secret;
        }
        void setFirst_name(std::string fname)
        {
            this.first_name = fname;
        }
        void setLast_name(std::string lname)
        {
            this.Last_name = lname;
        }
        void setNick_name(std::string nname)
        {
            this.nick_name = nname;
        }
        void setPhone_num(std::string phone)
        {
            this.Phone_num = phone;
        }
        void setDarck_secret(std::string secret)
        {
            this.darck_secret = secret;
        }
}

#endif