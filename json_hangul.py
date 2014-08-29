# coding: utf8
# 위 한 줄을 추가해야 IDE에서 utf8로 에디팅이 된다.
# 즉 한글이 잘 보인다.

    view_info["hangul test"] = "한글은 잘 나오냐"
    
    return json.dumps(view_info, ensure_ascii=False)

# 유니코드 인코딩, iconv 지랄쌈싸먹지 말고 ensure_ascii 면 땡이다..

