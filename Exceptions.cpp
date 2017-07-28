/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <exception>
#include <string>

class TooManyArgs_Error : public std::exception
{
    public:
        explicit TooManyArgs_Error (const std::string& file,
                const std::string& line)
        {
            m_file = file;
            m_line = line;
        }
        virtual const char* what() const throw()
        {
            return ("Too many args present in file " + m_file + " at line "
                    + m_line).c_str();
        }
    private:
        std::string m_file;
        std::string m_line;
};


class TwoType_Error : public std::exception
{
    public:
        explicit TwoType_Error (const std::string& file,
                const std::string& line)
        {
            m_file = file;
            m_line = line;
        }
        virtual const char* what() const throw()
        {
            return ("Object is defined a second time in file " + m_file
                    + " at line " + m_line).c_str();
        }
    private:
        std::string m_file;
        std::string m_line;
};