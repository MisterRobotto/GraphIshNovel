/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <exception>
#include <string>

#include <iostream>

class Gin_Error : public std::exception
{
    public:
        explicit Gin_Error (const std::string& file, const int& line,
                const std::string& error)
        {
            m_file = file.substr(file.find_last_of("\\")+1);
            m_line = std::to_string(line);
            m_error = error;
        }
        explicit Gin_Error (const std::string& file, const std::string& line,
                const std::string& error)
        {
            m_file = file.substr(file.find_last_of("\\")+1);
            m_line = line;
            m_error = error;
        }
        virtual const char* what() const throw()
        {
            return (m_error + " in file ").append(m_file + " at line ")
                    .append(m_line).c_str();
        }
    protected:
        std::string m_file;
        std::string m_line;
        std::string m_error;
};

/*
 * ArgsMismatch_Error is used when the given and expected number of arguments
 *  do not match
 */
class ArgsMismatch_Error : public Gin_Error
{
    public:
        explicit ArgsMismatch_Error (const std::string& file,
                const int& line) : Gin_Error(file, line,
                        "Given and expected argument counts do not match"){}
        explicit ArgsMismatch_Error (const std::string& file,
                const std::string& line) : Gin_Error(file, line,
                        "Given and expected argument counts do not match"){}
};


/*
 * TwoType_Error is used when an object attempts to define its type twice
 */
class TwoType_Error : public Gin_Error
{
    public:
        explicit TwoType_Error (const std::string& file,
                const int& line) : Gin_Error(file, line,
                        "Object type is defined a second time"){}
        explicit TwoType_Error (const std::string& file,
                const std::string& line) : Gin_Error(file, line,
                        "Object type is defined a second time"){}
};


class UnknownPrefix_Error : public Gin_Error
{
    public:
        explicit UnknownPrefix_Error (const std::string& file,
                const int& line) : Gin_Error(file, line,
                        "Unknown or invalid prefix given"){}
        explicit UnknownPrefix_Error (const std::string& file,
                const std::string& line) : Gin_Error(file, line,
                        "Unknown or invalid prefix given"){}
};


class WrongPrefix_Error : public Gin_Error
{
    public:
        explicit WrongPrefix_Error (const std::string& file,
                const int& line) : Gin_Error(file, line,
                        "Prefix of wrong type present"){}
        explicit WrongPrefix_Error (const std::string& file,
                const std::string& line) : Gin_Error(file, line,
                        "Prefix of wrong type present"){}
};