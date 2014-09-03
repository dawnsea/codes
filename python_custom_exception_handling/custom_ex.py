# coding: utf8
import json

from gluon.debug import logger

# dawnsea, 2014/08/29
# 기본 에러 메세지들
defined_msg = {
    0       : u"No Error",
    1       : u"DB 접속 에러",
    999     : u"알 수 없는 에러",
    1000    : u"정의 되지 않은 에러",
    2000    : u"에러 처리 함수 테스트"
    }
# dawnsea, 2014/08/29
# 에러 메세지 처리
class rwd_error(BaseException):
    def __init__(self, code, data = None, traceback_msg = None):     
        
        self.code = code
        self.data = data
        self.traceback_msg = traceback_msg
        
        try:
            self.msg = defined_msg[code]
        except:
            self.msg = defined_msg[1000] 
            
    def to_json(self):
        response = {'error' : {'code' : self.code, 'msg' : self.msg }}
        
        logger.critical(self.msg)        
        
        if self.data is None:
            return json.dumps(response, ensure_ascii=False, sort_keys=False, indent=True)
        else:
            response.update(self.data)
            return json.dumps(response, ensure_ascii=False, sort_keys=False, indent=True)   
        
    def to_html(self):
        
        logger.critical(self.msg)        
        return "internal server error(%d)" % (self.code, self.msg)    
        
    def to_str(self):
        
        logger.critical(self.msg)
        return "CODE : %d, MSG : %s" % (self.code, self.msg)



