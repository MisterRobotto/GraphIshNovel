/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <exception>
#include <string>

/*
 * ArgsMismatch_Error is used when the given and expected number of arguments
 *  do not match
 */
class ArgsMismatch_Error : public std::exception
{
    public:
        explicit ArgsMismatch_Error (const std::string& file,
                const std::string& line)
        {
            m_file = file;
            m_line = line;
        }
        virtual const char* what() const throw()
        {
            return ("Given and expected numbers of arguments do not match in file "
                    + m_file + " at line " + m_line).c_str();
        }
    private:
        std::string m_file;
        std::string m_line;
};


/*
 * TwoType_Error is used when an object attempts to define its type twice
 */
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


class UnknownPrefix_Error : public std::exception
{
    public:
        explicit UnknownPrefix_Error (const std::string& file,
                const std::string& line)
        {
            m_file = file;
            m_line = line;
        }
        virtual const char* what() const throw()
        {
            return ("Unknown/Invalid prefix given in file " + m_file
                    + " at line " + m_line).c_str();
        }
    private:
        std::string m_file;
        std::string m_line;
};