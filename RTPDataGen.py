import os 
import datetime
import random
import base64

fr = open("test.csv", "r")
fw = open("output.csv", "w")

records = 0

line = fr.readline()
while line != "":
    
#    print line   
    line = line.split(",")

    ruid = str(line[0])
    adid = line[1]
    count = int(line[2]) + 1
   
#    print ruid, adid, count
    
    records = records + 1

    baseTime 	= "20131118102344100"   
    sessionId 	= "20131118102344100_" + ruid
	
    if random.randint(0, 4) == 0:
        memberId = ""
    else:
        memberId = str(random.randint(1000000000, 9000000000))
        
    token = "zx123fd34efx"
    deviceId = base64.b64encode(ruid)
    
    deviceModel = ["gal", "g", "ipho", ""]
    random.shuffle(deviceModel)  
    
    osName = ["win", "linux", "andro", "ios", ""]
    random.shuffle(osName)
    osVersion = str(random.randint(0, 3)) + "." + str(random.randint(0, 9))
    
    browserName = ["safa", "ie", "fire", "webk"]
    random.shuffle(browserName)
    
    browserVersion = str(random.randint(0, 9)) + "." + str(random.randint(0, 20))
    resolution = str(random.randint(0, 9))
    
    languageId = ["ko", "en", "jp", ""]
    random.shuffle(languageId)
    
    if random.randint(0, 5) > 0:    
        ip = str(random.randint(1, 254)) + "."      \
                + str(random.randint(1, 254)) + "." \
                + str(random.randint(1, 254)) + "." \
                + str(random.randint(1, 254))
    else:
        ip = ""

    networkType = str(random.randint(0, 4))
    
    carrierName = ["skt", "lgt", "kt"]
    random.shuffle(carrierName)
    
    logVersion = str(random.randint(0, 9)) + "." + str(random.randint(0, 20))
    appVersion = str(random.randint(0, 9)) + "." + str(random.randint(0, 20))
    
    currentPageName = ""
    currentPageCode = ""
    actionCode = ""
    actionName = ""
    actionValue = ""
    uuid = ruid
    siteCode = ""
    siteDomain = ""
    landingUrl = ""
    refUrl = ""
    categoryNo = ""
    categoryCd1 = ""
    categoryCd2 = ""
    categoryCd3 = ""
    categoryCd4 = ""
    productNo = adid
    productDescription = ""
    productPrice = ""
    productCount = ""
    searchKeyword = ""
    searchResCatCount = ""
    searchResCount = ""
    searchResProdNoList = ""


    rake_lib_version = str(random.randint(0, 9)) + "." + str(random.randint(0, 20))
    url = ""
    referrer = ""
    document_title = "" 
    current_page_name = ""
    current_page_code = ""
    action_code = ""
    action_name = ""
    action_value = ""
    action_value_detail = ""
    content_id = ""
    content_name = ""
    search_keyword = ""
    search_res_count = ""
    display_result = ""
    category_name = ""
    category_name_list = ""
    product_name = ""
    product_name_list = ""
    product_id = adid
    product_id_list = ""
    product_price = ""
    product_price_list = ""
    product_count = ""
    product_count_list = ""
    price = ""
    pay_method = ""
    discount_type = ""
    pay_method_detail = ""
    address_type = ""
    address_name = ""
    part_date = ""
    
    
    result_records =    \
            baseTime + "," \
            + sessionId + "," \
            + memberId + "," \
            + token + "," \
            + deviceId + "," \
            + deviceModel[0] + "," \
            + osName[0] + "," \
            + osVersion + "," \
            + browserName[0] + "," \
            + browserVersion + "," \
            + resolution + "," \
            + languageId[0] + "," \
            + ip + "," \
            + networkType + "," \
            + carrierName[0] + "," \
            + logVersion + ","    \
            + appVersion  + ","\
            + currentPageName   + "," \
            + currentPageCode + "," \
            + actionCode  + "," \
            + actionName  + "," \
            + actionValue + "," \
            + uuid  + "," \
            + siteCode  + "," \
            + siteDomain  + "," \
            + landingUrl  + "," \
            + refUrl  + "," \
            + categoryNo  + "," \
            + categoryCd1  + "," \
            + categoryCd2  + "," \
            + categoryCd3  + "," \
            + categoryCd4  + "," \
            + productNo  + "," \
            + productDescription  + "," \
            + productPrice  + "," \
            + productCount  + "," \
            + searchKeyword  + "," \
            + searchResCatCount  + "," \
            + searchResCount  + "," \
            + searchResProdNoList + "\n"

    
    while count != 0:
        fw.write(result_records)
        count = count - 1
        
    line = fr.readline()        

fw.close()
fw.close()

print "records = ", records


