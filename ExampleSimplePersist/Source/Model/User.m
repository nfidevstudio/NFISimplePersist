//
//  User.m
//  ExampleSimplePersist
//
//  Created by jcarlos on 15/2/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import "User.h"
#import "NFIEncode.h"

@implementation User

#pragma mark - Init

- (instancetype)initWithId:(NSString *)id user:(NSString *)user andPass:(NSString *)pass {
    self = [super init];
    if (self) {
        _user = user;
        _pass = pass;
        _id = id;
    }
    return self;
}

#pragma mark - Encode Methods

- (void)encodeWithCoder:(NSCoder *)encoder {
    [NFIEncode encodeWithCoder:encoder andClass:[self class]];
}

- (id)initWithCoder:(NSCoder *)decoder {
    return [NFIEncode initWithCoder:decoder andClass:[self class]];
}

#pragma mark - NFISimplePersistObjectProtocol

- (NSDictionary *)saveAsDictionary {
    return @{@"user" : _user,
            @"pass" : _pass,
            @"id" : _id
            };
}

- (instancetype)initWithDictionary:(NSDictionary *)dictionary {
    self = [super init];
    if (self) {
        _user = dictionary[@"user"];
        _pass = dictionary[@"pass"];
        _id = dictionary[@"id"];
    }
    return self;
}

@end
