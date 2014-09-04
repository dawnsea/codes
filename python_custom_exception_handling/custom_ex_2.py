# coding: utf8
# dawnsea, 2014/08/29
import json

from gluon.debug import logger

# dawnsea, 2014/08/29
# 기본 에러 메세지들
# 다국어 대응 T( 처리 연구도 필요함
defined_msg = {
    0       : u"No Error",
    1       : u"DB 접속 에러",
    999     : u"알 수 없는 에러",
    1000    : u"정의 되지 않은 에러",
    2000    : u"에러 처리 함수 테스트"
    }
# dawnsea, 2014/08/29
# 에러 메세지 처리
# 사용자에게는 읽을 수 있는 에러메시지를
# 개발자에게는 실제 익셉션 문장을 보여준다. 이 roll과 domain을 주의한다.
class rwd_error(BaseException):
    def __init__(self, code = None):     

        try:      
            self.code = code
        except:
            self.code = 1000        

        try:
            self.msg = defined_msg[code]
        except:
            self.msg = defined_msg[1000]
            
        logger.critical(self.msg)    
            
    def to_json(self):
        response = {'error' : {'code' : self.code, 'msg' : self.msg }}                     
        return json.dumps(response, ensure_ascii=False, sort_keys=False, indent=True)
          
    def to_html(self):                  
        return "internal server error(%d, %s)" % (self.code, self.msg)             
       
    def __str__(self):
#    def __unicode__(self):  
        return unicode("CODE : %d, MSG : %s" % (self.code, self.msg)).encode('utf-8')
    
    def to_str(self):
        return "CODE : %d, MSG : %s" % (self.code, self.msg)
        
            

"""
class rwd_error(BaseException):
    def __init__(self, code):     
        
        
        self.code = code

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
        return "internal server error(%d, %s)" % (self.code, self.msg)    
        
    def __str__(self):
        logger.critical(self.msg)
        return str("CODE : %d, MSG : %s" % (111, "dfsdfds"))

        if self.traceback_msg != None:
            return str("CODE : %d, MSG : %s, TRACE : %s" % (self.code, self.msg, self.traceback_msg))
        else:
            return str("CODE : %d, MSG : %s" % (self.code, self.msg))


"""

