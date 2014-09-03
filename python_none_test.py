def test_none():
    ret_msg = ''
    vs_msg = None
    
    if '' == None:
        ret_msg = '"" == None'     
    else:
        ret_msg = "*1*"
     
    if '' is None:
        ret_msg += ' "" is None'
    else:
        ret_msg += "*2*"    
        
    if '' == '':
        ret_msg += ' "" == ""'
    else:
        pass
        
    if vs_msg == "":
        ret_msg += ' None var == ""'
        
    return ret_msg

