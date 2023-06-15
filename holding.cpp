#include "holding.h"
#include <curl/curl.h>
#include <json/json.h>

Holding::Holding(string _ticker) {
    ticker = _ticker;
    numShares = 0;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


double Holding::getSharePrice() {
    CURL *curl;
    CURLcode res;
    std::string response;
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json"); 

    curl = curl_easy_init();
    if(curl) {
        string url = "https://query1.finance.yahoo.com/v11/finance/quoteSummary/" + ticker + "?modules=financialData";
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        Json::Reader reader;
        Json::Value completeJsonData;

        reader.parse(response, completeJsonData);
        double currentPrice = completeJsonData["quoteSummary"]["result"][0]["financialData"]["currentPrice"][ "raw"].asDouble();

        return currentPrice;
    }

    return 0; // TODO throw error
}

double Holding::sellShare(int num) {
    numShares -= num;
    return num * getSharePrice();
}

double Holding::buyShare(int num) {
    numShares += num;

    return num * getSharePrice();
}

double Holding::getCurrentValuation() {
    return numShares * getSharePrice();
}

int Holding::getNumShares() {
    return numShares;
}

bool Holding::exists() {
    CURL *curl;
    CURLcode res;
    std::string response;
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json"); 

    curl = curl_easy_init();
    if(curl) {
        string url = "https://query1.finance.yahoo.com/v11/finance/quoteSummary/" + ticker + "?modules=financialData";
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        Json::Reader reader;
        Json::Value completeJsonData;

        reader.parse(response, completeJsonData);
        completeJsonData["quoteSummary"]["error"];

        return !completeJsonData["quoteSummary"].get("error", false);
    }

    return false;
}