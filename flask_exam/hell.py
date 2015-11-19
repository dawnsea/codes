from flask import Flask
import init
from console_notice import print_console
#import tblog_log

#from flask.ext.uuid import FlaskUUID

application = Flask(__name__)
app = application

app.debug = False

init.global_init('./config.yaml')

#tblog_log.init_log('./log_config.yaml')

'''
if not app.debug:
    import logging, logging.handlers

    global_log_handler = logging.handlers.TimedRotatingFileHandler("myer", when = 'S')
    global_log_handler.suffix = "%Y%m%d:%H%M.log"
    
    log_format = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    
    global_log_handler.setFormatter(log_format)
    
    app.logger.addHandler(global_log_handler)
    
    app.logger.setLevel(logging.DEBUG)
    app.logger.debug("나는 디버그")
    app.logger.info("나는 인포")
    app.logger.warn("나는 워닝")
'''    

	
    
     

"""
import logging

logging.warning('Watch out!') # will print a message to the console
logging.info('I told you so') # will not print anything
"""



"""
flask_uuid = FlaskUUID()
flask_uuid.init_app(app)
"""

@app.route('/hello')
def hello_world(): 
    return 'Hello World!233'
"""    
@app.route('/<uuid(strict=False):id>')
def mypage(id):
	return id    
"""    
if __name__ == '__main__':
    app.run(debug=True)


