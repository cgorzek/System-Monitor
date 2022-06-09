#ifndef UTILS_H
#define UTILS_H

#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include <errno.h>
#include <sys/stat.h>

namespace utils {
    /******************************************************************************
     * Checks to see if a directory exists. Note: This method only checks the
     * existence of the full path AND if path leaf is a dir.
     *
     * @return  >0 if dir exists AND is a dir,
     *           0 if dir does not exist OR exists but not a dir,
     *          <0 if an error occurred (errno is also set)
     *****************************************************************************/
    /*
    int dirExists(const char* const path)
    {
        struct stat info;

        int statRC = stat( path, &info );
        if( statRC != 0 )
        {
            if (errno == ENOENT)  { return 0; } // something along the path does not exist
            if (errno == ENOTDIR) { return 0; } // something in path prefix is not a dir
            return -1;
        }

        return ( info.st_mode & S_IFDIR ) ? 1 : 0;
    }
    */

    // split - for splitting strings on delimiter
    std::vector<std::string> split (std::string s, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }
}

#endif