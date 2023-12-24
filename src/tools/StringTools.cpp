#include "tgbot/tools/StringTools.h"

#include <iomanip>
#include <random>
#include <string>


namespace StringTools {

    bool startsWith(const std::string &str1, const std::string &str2) {
        if (str1.length() < str2.length()) {
            return false;
        }
        std::string::const_iterator it1(str1.begin());
        std::string::const_iterator it2(str2.begin());
        std::string::const_iterator end2(str2.end());
        while (it2 != end2) {
            if (*it1 != *it2) {
                return false;
            }
            ++it1;
            ++it2;
        }
        return true;
    }


    bool endsWith(const std::string &str1, const std::string &str2) {
        if (str1.length() < str2.length()) {
            return false;
        }
        std::string::const_iterator it1(str1.end());
        std::string::const_iterator it2(str2.end());
        std::string::const_iterator begin2(str2.begin());
        --begin2;
        while (it2 != begin2) {
            if (*it1 != *it2) {
                return false;
            }
            --it1;
            --it2;
        }
        return true;
    }


    std::string generateRandomString(std::size_t length) {
        static const std::string chars(
                "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890-=[]\\',./!@#$%^&*()_+{}|:\"<>?`~");

        static const std::size_t charsLen = chars.length();
        std::string result;

        std::random_device randomDevice;
        std::mt19937 randomSeed(randomDevice());
        std::uniform_int_distribution<std::size_t> generator(0, charsLen - 1);

        for (std::size_t i = 0; i < length; ++i) {
            result += chars[generator(randomSeed)];
        }
        return result;
    }


    std::string urlEncode(const std::string &value, const std::string &additionalLegitChars) {
        static const std::string legitPunctuation = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_.-~:";
        std::stringstream ss;
        for (auto const &c: value) {
            if ((legitPunctuation.find(c) == std::string::npos) &&
                (additionalLegitChars.find(c) == std::string::npos)) {
                ss << '%' << std::uppercase << std::setfill('0') << std::setw(2) << std::hex
                   << (unsigned int) (unsigned char) c;
            } else {
                ss << c;
            }
        }

        return ss.str();
    }


    std::string urlDecode(const std::string &value) {
        std::string result;
        for (std::size_t i = 0, count = value.length(); i < count; ++i) {
            const char c = value[i];
            if (c == '%') {
                int t = stoi(value.substr(i + 1, 2), nullptr, 16);
                result += (char) t;
                i += 2;
            } else {
                result += c;
            }
        }
        return result;
    }


    std::vector<std::string> split(const std::string &str, char delimiter) {
        std::vector<std::string> result;
        std::istringstream stream(str);
        std::string s;
        while (getline(stream, s, delimiter)) {
            result.push_back(s);
        }
        return result;
    }


    std::string escapeJsonString(const std::string &value) {
        std::string result;

        for (const char &c: value) {
            switch (c) {
                case '"':
                case '\\':
                case '/':
                    result += '\\';
                    break;
            }

            result += c;
        }

        return result;
    }
}
