/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GinManager.cpp
 * Author: ConnorFlynn
 * 
 * Created on July 16, 2017, 10:09 PM
 */

#include "GinManager.h"

/*
 * Name: GinManager(string) 
 * Desc: Constructor
 * Prec: Takes in a filepath containg .gnf and/or .ginf files
 * Post: Creates the GinManager object with loaded subobjects
 */
GinManager::GinManager(const std::string path)
{
    LoadSettings();
    LoadDirectory(path);
}

GinManager::GinManager(const GinManager& orig) {
}


/*
 * Name: ~GinManager
 * Desc: Destructor
 * Prec: None
 * Post: Deletes content of and clears pointer maps
 */
GinManager::~GinManager()
{
    // m_characters
    for (std::map<std::string,Character*>::iterator it = m_characters.begin() ;
            it != m_characters.end(); ++it)
   {
     delete (*it).second;
   } 
   m_characters.clear();
      
   // m_events
    for (std::map<std::string,Event*>::iterator it = m_events.begin() ;
            it != m_events.end(); ++it)
   {
     delete (*it).second;
   } 
   m_events.clear();
   
   // m_locations
    for (std::map<std::string,Location*>::iterator it = m_locations.begin() ;
            it != m_locations.end(); ++it)
   {
     delete (*it).second;
   } 
   m_locations.clear();

   
   // m_menus
    for (std::map<std::string,Menu*>::iterator it = m_menus.begin() ;
            it != m_menus.end(); ++it)
   {
     delete (*it).second;
   } 
   m_menus.clear();
   
   // m_scenes
    for (std::map<std::string,Scene*>::iterator it = m_scenes.begin() ;
            it != m_scenes.end(); ++it)
   {
     delete (*it).second;
   } 
   m_scenes.clear();
}

/* [NOTE - REMEMBER TO UPDATE WITH ALL NEW CHANGES ADDED TO FUNCTION]
 * Name: LoadSettings
 * Desc: Defines some settings, such as object type vector
 * Prec: None -- runs only when new instance created
 * Post: Defines settings:
 *          - m_driver as NULL
 *          - m_object_types (vector of object types)
 *              - m_object_types_regex (regex OR of all object types)
 *          - vectors of valid object prefixes
 *              - associated regex ORs
 *          - m_collections (vector of "collection" types)
 *              - m_collections_regex (regex OR of "collection" types)
 */
void GinManager::LoadSettings()
{    
    m_driver;
    
    std::vector<std::string> all_prefixes;
    
    /*
     * Object Types
     */
    m_object_types.push_back("char");
    m_object_types.push_back("character");
    m_object_types.push_back("location");
    m_object_types.push_back("event");
    m_object_types.push_back("scene");
    m_object_types.push_back("menu");
    m_object_types.push_back("driver");
    
    m_object_types_regex = MakeRegex(m_object_types);
    
    all_prefixes.insert(all_prefixes.end(), m_object_types.begin(),
            m_object_types.end());
    
    /*
     * Valid Character prefixes
     */
    m_char_prefixes.push_back("name");
    m_arg_count["name"] = 2;
    
    m_char_prefixes.push_back("prefer");
    m_arg_count["prefer"] = 2;
    
    m_char_prefixes.push_back("short");
    m_arg_count["short"] = 2;
    
    m_char_prefixes.push_back("color");
    m_arg_count["color"] = 2;
    
    m_char_prefixes.push_back("image");
    m_arg_count["image"] = 3;
    
    m_char_prefixes.push_back("say");
    m_arg_count["say"] = 3;
    
    
    m_char_prefixes_regex = MakeRegex(m_char_prefixes);
    
    all_prefixes.insert(all_prefixes.end(), m_char_prefixes.begin(),
            m_char_prefixes.end());
    
    
    /*
     * Valid Location Prefixes
     * (WARNING: Highly subject to change)
     */
    m_loc_prefixes.push_back("background");
    m_arg_count["background"] = 2;
    
    m_loc_prefixes.push_back("events");
    m_arg_count["events"] = 1;
    
    m_loc_prefixes.push_back("map_name");
    m_arg_count["map_name"] = 2;
    
    m_loc_prefixes.push_back("referred");
    m_arg_count["referred"] = 2;
    
    m_loc_prefixes.push_back("adjacent");
    m_arg_count["adjacent"] = 1;
    
    
    m_loc_prefixes_regex = MakeRegex(m_loc_prefixes);
    
    all_prefixes.insert(all_prefixes.end(), m_loc_prefixes.begin(),
            m_loc_prefixes.end());
    
    
    /*
     * Valid Scene Prefixes
     */
    m_scne_prefixes.push_back("setting");
    m_arg_count["setting"] = 2;
    
    m_scne_prefixes.push_back("start_flow");
    m_arg_count["start_flow"] = 2;
    
    m_scne_prefixes.push_back("flow");
    m_arg_count["flow"] = 2;
    
    m_scne_prefixes.push_back("say");
    m_arg_count["say"] = 3;
    
    m_scne_prefixes.push_back("if");
    m_arg_count["if"] = 2;
    
    m_scne_prefixes.push_back("elif");
    m_arg_count["elif"] = 2;
    
    m_scne_prefixes.push_back("else");
    m_arg_count["else"] = 1;
    
    m_scne_prefixes.push_back("while");
    m_arg_count["while"] = 2;
    
    m_scne_prefixes.push_back("play");
    m_arg_count["play"] = 2;
    
    m_scne_prefixes.push_back("branch");
    m_arg_count["branch"] = 2;
    
    m_scne_prefixes.push_back("display");
    m_arg_count["display"] = 2;
    
    m_scne_prefixes.push_back("choice");
    m_arg_count["choice"] = 2;
    
    m_scne_prefixes.push_back("response");
    m_arg_count["response"] = 2;
    
    m_scne_prefixes_regex = MakeRegex(m_scne_prefixes);
    
    all_prefixes.insert(all_prefixes.end(), m_scne_prefixes.begin(),
            m_scne_prefixes.end());
    
    /*
     * Valid Menu Prefixes
     * (WARNING: Highly subject to change)
     */
    m_menu_prefixes.push_back("section");
    m_arg_count["section"] = 2;
    
    m_menu_prefixes.push_back("button");
    m_arg_count["button"] = 2;
    
    m_menu_prefixes.push_back("image");
    m_arg_count["image"] = 2;
    
    m_menu_prefixes.push_back("position");
    m_arg_count["position"] = 3;
    
    m_menu_prefixes.push_back("dropdown");
    m_arg_count["dropdown"] = 2;
    
    m_menu_prefixes.push_back("play");
    m_arg_count["play"] = 2;
    
    m_menu_prefixes.push_back("start");
    m_arg_count["start"] = 2;
    
    m_menu_prefixes.push_back("set");
    m_arg_count["set"] = 2;
    
    m_menu_prefixes_regex = MakeRegex(m_menu_prefixes);
    
    all_prefixes.insert(all_prefixes.end(), m_menu_prefixes.begin(),
            m_menu_prefixes.end());
    
    /*
     * Valid Driver Prefixes
     * (WARNING: Highly subject to change)
     */
    m_drvr_prefixes.push_back("MAIN_DRIVER");
    m_arg_count["MAIN_DRIVER"] = 1;
    
    m_drvr_prefixes.push_back("vars");
    m_arg_count["vars"] = 1;
    
    m_drvr_prefixes.push_back("start");
    m_arg_count["start"] = 2;
    
    m_drvr_prefixes.push_back("include");
    m_arg_count["include"] = 1;
    
    m_drvr_prefixes_regex = MakeRegex(m_drvr_prefixes);
    
    all_prefixes.insert(all_prefixes.end(), m_drvr_prefixes.begin(),
            m_drvr_prefixes.end());
    
    /*
     * TODO: See issue #1
    /*
     * Variable Types
     *\/
    m_var_types.push_back("int");
    m_var_types.push_back("string");
    m_var_types.push_back("double");
    m_var_types.push_back("bool");
     */
    
    m_all_prefixes_regex = MakeRegex(all_prefixes);
    
    /*
     * "Collection" Types
     * "Collections" are structures that have nested statements that do not
     *      have a valid prefix. For now, we ignore them.
     */
    m_collections.push_back("events");
    m_collections.push_back("adjacent");
    m_collections.push_back("include");
    // [TODO] When variable types are implemented, remove the following line
    m_collections.push_back("vars");
    
    // Collection types will all end with a colon so just roll them in
    m_colon_check.insert(m_colon_check.end(), m_collections.begin(),
            m_collections.end());
    
    m_collections_regex = MakeRegex(m_collections);
    
    /*
     * Colon Check List
     * Any statement that needs to end with a colon
     */
    m_colon_check.push_back("flow");
    m_colon_check.push_back("if");
    m_colon_check.push_back("elif");
    m_colon_check.push_back("else");
    m_colon_check.push_back("while");
    m_colon_check.push_back("choice");
    m_colon_check.push_back("response");
    
    m_colon_check_regex = MakeRegex(m_colon_check);
}

/*
 * Name: LoadFile
 * Desc: Takes in a file path, reads its contents, and initializes the object
 * Prec: A valid .gnf file path
 * Post: Initializes the object defined in the .gnf file
 */
void GinManager::LoadFile(const std::string path) throw()
{
    // Load the file's contents into a vector
    std::vector<std::string> lines;
    std::ifstream file;
    file.open(path.c_str());
    char chr_input[1024];
    while(file.peek() != EOF)
    {
        file.getline(chr_input,1024,';');
        lines.push_back(chr_input);
    }
    
    // Clean whitespace
    for(std::vector<std::string>::iterator line = lines.begin();
            line != lines.end(); ++line)
    {
        // Replace newlines with spaces, delete tabs
        for(std::string::iterator it = line->begin(); it != line->end(); ++it)
        {
            if(*it == '\n')
            {
                (*it) = ' ';
            }
            else if(*it == '\t')
            {
                it = line->erase(it);
                --it;
            }
        }
        
        // Remove leading + trailing spaces
        while(line->front() == ' ')
        {
            line->erase(line->begin());
        }
        while(line->back() == ' ')
        {
            line->erase(line->end());
        }
    }
    
    bool in_collection;
    int coll_indent;
    
    std::string type = "NULL";
    std::string id;
    std::regex valid_prefixes;
    int i = 0;
    // Read every line in the vector
    for(std::vector<std::string>::iterator it = lines.begin();
            it != lines.end(); ++it)
    {
        std::string line = *it;
        i++;
        
        std::cout << "\"" << line << "\"" << std::endl;
        
        int curr_indent = 0;
        /*
         * Indentation does not matter now, so get rid of it before problems
         *      Keep track of indentation, though
         */
        while(line.front() == ' ' || line.front() == '\t')
        {
            line.erase(0,1);
            curr_indent++;
        }
        std::string prefix = line.substr(0,line.find_first_of(" "));
        
        /*
        // If prefix ends with a colon, drop it
        if(prefix.back() == ':')
        {
            prefix.pop_back();
        }
        */
        
        /*
         * If curr_indent is not greater than coll_indent and isn't a comment
         *      or whitespace, then we're not in a collection anymore
         */
        if(curr_indent <= coll_indent &&
                !(!std::regex_match(prefix,std::regex("\\S+")) ||
                prefix.front() == '#'))
        {
            coll_indent = 0;
            in_collection = false;
        }
        
        /*
         * If in collection, just skip it (for now)
         */
        if(in_collection){}
        
        /*
         * CHECK IF OBJECT TYPE DECLARATION
         */
        // Else if the prefix is an object type
        else if(std::regex_match(prefix, m_object_types_regex))
        {
            // If it has two arguments
            if(HasArgs(line,2))
            {
                // If the type is not defined
                if(type == "NULL")
                {
                    // Define it
                    type = prefix;
                    
                    /*
                     * Conditions over type, including:
                     *  - regex setting
                     *  - shortenings
                     */
                    if(type == "character")
                    {
                        type = "char";
                        valid_prefixes = m_char_prefixes_regex;
                    }
                    else if(type == "char")
                    {
                        valid_prefixes = m_char_prefixes_regex;
                    }
                    else if(type == "location")
                    {
                        valid_prefixes = m_loc_prefixes_regex;
                    }
                    else if(type == "event" || type == "scene")
                    {
                        valid_prefixes = m_scne_prefixes_regex;
                    }
                    else if(type == "menu")
                    {
                        valid_prefixes = m_menu_prefixes_regex;
                    }
                    else if(type == "driver")
                    {
                        valid_prefixes = m_drvr_prefixes_regex;
                    }
                    
                    
                    // Get the identifier
                    id = line.substr(prefix.size() + 1);
                    
                    // Remove the type definition; it's not needed anymore
                    it = lines.erase(it);
                    --it;
                }
                // If it is, throw TwoType_Error
                else
                {
                    throw DoubleDef_Error("Object type", path, i);
                }
            }
            // If it does not, throw ArgsMismatch_Error
            else
            {
                std::cout << "\"" << line << "\"" << std::endl;
                throw ArgsMismatch_Error(path, i);
            }
        }
        
        /*
         * FUTURE PREFIX IMPLEMENTATIONS GO HERE
         */
        
        /*
         * Else if a comment / all-whitespace line, remove it
         */
        else if(!std::regex_match(prefix,std::regex("\\S+")) ||
                prefix.front() == '#')
        {
            it = lines.erase(it);
            --it;
        }
        
        /*
         * Else if a valid prefix, but not for this object's type,
         *      throw WrongPrefix_Error
         */
        else if(std::regex_match(prefix,m_all_prefixes_regex) &&
                !std::regex_match(prefix,valid_prefixes))
        {
            throw WrongPrefix_Error(path, i);
        }
        
        /*
         * Else if a "collection" type, go into collection mode
         */
        else if(std::regex_match(prefix,m_collections_regex))
        {
            coll_indent = curr_indent;
            in_collection = true;
        }
        
        /*
         * Else if prefix does not match any valid prefix, throw UnknownPrefix_Error
         */
        else if(!std::regex_match(prefix,m_all_prefixes_regex))
        {
            throw UnknownPrefix_Error(path, i+1);
        }
        
        
        /*
         * If line's args do not match prefix's expected args, throw an
         *      ArgsMismatch_Error
         */
        if(m_arg_count.count(prefix) > 0 && !HasArgs(line,m_arg_count[prefix]))
        {
            std::cout << "\"" << line << "\"" << std::endl;
            throw ArgsMismatch_Error(path, i);
        }
        
        /*
         * If prefix should be checked for colon and last char isn't a colon,
         *      throw a NoColon_Error
         */
        if(std::regex_match(prefix,m_colon_check_regex) && line.back() != ':')
        {
            throw NoColon_Error(path, i);
        }
    }
    
        
    /*
     * Go through newly-combed lines and create 2D vector of lines' args
     */
    std::vector<std::vector<std::string>> line_args;
    
    for(std::vector<std::string>::iterator it = lines.begin();
            it != lines.end(); ++it)
    {
        line_args.push_back(GetArgs(*it));
    }
    //for(auto x : line_args){for(auto y : x) std::cout << y << " "; std::cout << std::endl;} std::cout << std::endl;
    
    /*
     * If type was never defined, throw NoType_Error
     */
    if(type == "NULL")
    {
        throw NoType_Error(path);
    }
    try
    {
        /*
         * Create associated object, add it to m_objects and the relevant
         *      type vector
         */
        // Character
        if(type == "char")
        {
            m_objects[id] = character;
            m_characters[id] = new Character(line_args);
        }
        //Driver
        else if(type == "driver")
        {
            // [TODO]
        }
        // Event
        else if(type == "event")
        {
            m_objects[id] = event;
            m_events[id] = new Event(line_args);
        }
        // Location
        else if(type == "location")
        {
            m_objects[id] = location;
            m_locations[id] = new Location(line_args);
        }
        // Menu
        else if(type == "menu")
        {
            m_objects[id] = menu;
            m_menus[id] = new Menu(line_args);
        }
        // Scene
        else if(type == "scene")
        {
            m_objects[id] = scene;
            m_scenes[id] = new Scene(line_args);
        }
    }
    catch(std::pair<std::string, int> e)
    {
        throw DoubleDef_Error(e.first, path, e.second);
    }
}

/* 
 * Name: LoadDirectory
 * Desc: Takes in the path to a directory file and completes all steps therein
 * Prec: A .gnd file path
 * Post: Loads all the objects from the files in the directory.
 */
void GinManager::LoadDirectory(const std::string path)
{
    std::ifstream directory_file;
    directory_file.open(path.c_str());
    
    // Directory vector and char array for input
    std::vector<std::string> directory;
    char chr_input[1024];
    
    // Read all the lines into the vector
    while(directory_file.peek() != EOF)
    {
        directory_file.getline(chr_input,80);
        directory.push_back(chr_input);
    }
    
    // Current directory string, current file string, and current type char
    std::string curr_directory;
    char type;
    std::string file;
    for(int i = 0; i < directory.size(); i++)
    {
        // Type is the first character, file is from 2 to the end
        type = directory.at(i).at(0);
        file = directory.at(i).substr(2);
        
        // If type is 'd', set the current directory
        if(type == 'd')
        {
            curr_directory = file;
            // If the directory doesn't end with a slash, add it
            if(curr_directory.find_last_of("\\") != curr_directory.length()-1)
            {
                curr_directory.append("\\");
            }
        }
        
        // Else if type is 'f', load the file
        else if(type == 'f')
        {
            /*
             * Catch any TwoMainDriver_Error so that the correct info can
             *      be passed to the error
             */
            try
            {
                file = curr_directory + file;
                LoadFile(file);
            }
            catch(TwoMainDriver_Error e)
            {
                throw TwoMainDriver_Error(path,i);
            }
        }
        
        // Else if type is 'i', load a different directory
        else if(type == 'i')
        {
            LoadDirectory(file);
        }
    }
}

/*
 * Name: HasArgs
 * Desc: Determines if a given line has a certain number of arguments
 * Prec: A string and an integer
 * Post: Returns true if the line has arg_num arguments, false otherwise
 */
bool GinManager::HasArgs(std::string line, int arg_num)
{
    // Set the single-argument test
    std::string arg_bit = "(<[^<>]+>|\\([^\\(\\)]+\\)|[^\"\\s]+|\"[^\"]+\")";
    
    // Try-Catch just in case a change to the Regex makes it flip out
    try{
        // Start with start-of-line flag, open-paren, and a single-argument test
        std::string regex_test_str = "^(" + arg_bit;
        // From 1 to arg_num (ie. arg_num - 1 times)
        for(int i = 1; i < arg_num; i++)
        {
            // Add another single-argument test
            regex_test_str.append(" " + arg_bit);
        }
        // End with a close-paren and end-of-line flag
        regex_test_str.append(")$");
        std::regex regex_test_rgx(regex_test_str);

        return std::regex_match(line, regex_test_rgx);
    }
    catch(std::regex_error& e)
    {
        std::cout << e.code() << std::endl;
        if(e.code() == std::regex_constants::error_paren)
            std::cout << "error_paren" << std::endl;
        throw;
    }
}


/*
 * Name: GetArgs
 * Desc: Gets the arguments from a line
 * Prec: A string
 * Post: Returns a vector of the arguments
 */
std::vector<std::string> GinManager::GetArgs(std::string line)
{
    std::string arg_bit = "(<[^<>]+>|\\([^\\(\\)]+\\)|[^\"\\s]+|\"[^\"]+\")";
    std::regex rgx(arg_bit);
    std::smatch match;
    std::vector<std::string> output;
    
    while (std::regex_search(line, match, rgx))
    {
        output.push_back(match[0]);
        line = match.suffix().str();
    }
    return output;
}


/*
 * Name: MakeRegex
 * Desc: Takes in a vector and returns the matching regex OR statement
 * Prec: A non-empty string vector
 * Post: A regex containing the regex OR of the contents of vec
 */
std::regex GinManager::MakeRegex(std::vector<std::string> vec)
{
    // Begin with a start-of-string flag and open-paren
    std::string objects_regex = "^(";
    // For every string in vec
    for(int i = 0; i < vec.size(); i++)
    {
        // Add that string and the OR flag '|'
        objects_regex.append(vec.at(i) + "|");
    }
    // Replace the trailing OR flag with a close-paren
    objects_regex.back() = ')';
    // Add an end-of-string flag
    objects_regex.append("$");
    
    // Make a regex object with the string and return it
    std::regex output(objects_regex);
    return output;
}