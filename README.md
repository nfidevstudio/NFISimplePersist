# NFISimplePersist - v 0.1.1

### The best way to persist data into sqlite without problems.

First, add to your project the <strong>libsqlite3.0.tdb</strong> framework. 

Then, import:

```Objective-c
#import "NFISimplePersist.h"
```

Its mandatory that your entity implements the NFISimplePersistObjectProtocol, like:

```objective-c
#import "User.h"

@interface User () <NFISimplePersistObjectProtocol> 

@end

@implementation User

#pragma mark - Init

- (instancetype)initWithId:(NSInteger)id user:(NSString *)user andPass:(NSString *)pass {
    self = [super init];
    if (self) {
        _user = user;
        _pass = pass;
        _id = id;
    }
    return self;
}

#pragma mark - NFISimplePersistObjectProtocol

- (NSDictionary *)saveAsDictionary {
    return @{@"user" : _user,
            @"pass" : _pass,
            @"id" : [NSNumber numberWithInteger:_id]
            };
}

- (instancetype)initWithDictionary:(NSDictionary *)dictionary {
    self = [super init];
    if (self) {
        _user = dictionary[@"user"];
        _pass = dictionary[@"pass"];
        _id = [dictionary[@"id"] integerValue];
    }
    return self;
}

@end
```

# NFISimplePersist Usage

NFISimplePersist works with a singleton:

```Objective-c
[NFISimplePersist standarSimplePersist];
```

You can save all kind of entities:  

```objective-c
NFISimplePersist *persist = [NFISimplePersist standarSimplePersist];
User *user = [[User alloc] initWithId:1 user:@"NFI" andPass:@"no-pass"];
[persist saveObject:user withKey:[NSString stringWithFormat:@"%ld",user.id]];
```


To get some object:

```objective-c
NFISimplePersist *persist = [NFISimplePersist standarSimplePersist];
[persist loadObjectWithKey:@"1"];
```

You can get all objects of the same class:

```objective-c
NFISimplePersist *persist = [NFISimplePersist standarSimplePersist];
[persist loadAllObjectsWithClass:[User class]];
```

To remove it:

```objective-c
NFISimplePersist *persist = [NFISimplePersist standarSimplePersist];
[persist removeObjectWithKey:@"1"];
```
### Now, enjoy it!!