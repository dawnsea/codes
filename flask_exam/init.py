import yaml
import logging
from console_notice import print_console
'''
def console_log_init():
	logger = logging.getLogger('global_console_logger')
	logger.setLevel(logging.INFO)
	
	ch = logging.StreamHandler()
	ch.setLevel(logging.INFO)
	
	formatter = logging.Formatter('[%(asctime)s] %(message)s')
	ch.setFormatter(formatter)
	
	logger.addHandler(ch)
	return logger
'''

def read_config(config_file):
	
	try:
		with open(config_file, 'r') as stream:
			config_doc = yaml.load(stream)
	except:
		print_console('로그 설정 파일 읽기 에러')
		raise
		
	return config_doc
		

def global_init(config_file):
	

	print_console('=====tblog 시작=====')
	
	try:
		g_config = read_config(config_file)
		
	except:
		print '전역 설정 파일 읽기 에러'
		raise
		
		
	
	if g_config['log_config']:
		log_config = read_config(g_config['log_config'])
			
		
