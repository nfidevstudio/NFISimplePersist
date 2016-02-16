# NFISimplePersist - v 0.1

The best way to persist data into sqlite without problems.

Works with a singleton:

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