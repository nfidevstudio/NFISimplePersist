//
//  LPUser.m
//  LeasePlan
//
//  Created by José Carlos on 18/1/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import "LPUser.h"

@implementation LPUser

#pragma mark - Init 

- (instancetype)init {
    self = [super init];
    if (self) {
        
    }
    return self;
}

#pragma mark - Public methods

- (NSString *)description {
    return [NSString stringWithFormat:@"<LPUser Name: %@>",_name];
}

#pragma mark - NFISimplePersistObject

- (NSDictionary *)saveAsDictionary {
    NSDictionary *dict = [[NSDictionary alloc] initWithObjects:@[_name, _surname,]
                                                       forKeys:@[@"name", @"surname"]];
    return dict;
}

- (instancetype)initWithDictionary:(NSDictionary *)dictionary {
    self = [super init];
    if (self) {
        _name = [dictionary objectForKey:@"name"];
        _surname = [dictionary objectForKey:@"surname"];
    }
    return self;
}


@end
