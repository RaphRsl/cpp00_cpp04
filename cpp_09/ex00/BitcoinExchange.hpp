#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <map>
# define VERBOSE 0

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& bitExch);
        ~BitcoinExchange(void);

        BitcoinExchange& operator=(const BitcoinExchange& bitExch);

        void parseDataCsv(std::ifstream& data_csv);

        float getMatchingExchRate(const std::string& date);

        bool checkDateFormat(const std::string &date);
        bool checkDateValid(const std::string& date);
        bool checkExchrateValid(const std::string& exchRate,  const std::string& date);

    private:
        std::map<std::string, float> dataBase;
};

#endif