    try:
        raise rwd_error(2000)
    
    except rwd_error as e:
        return e.to_json()

