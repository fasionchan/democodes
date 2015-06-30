# pymongo

### 更新

```
# 更新不存在则插入
collections.update({'ip': '1.1.1.1'}, {'ip': '1.1.1.1', 'key': 1111}, upsert=True)
```

### 索引

``` py
# 唯一索引
collection.ensure_index([('ip', pymongo.ASCENDING)], unique=True)
```
