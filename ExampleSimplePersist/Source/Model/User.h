//
//  User.h
//  ExampleSimplePersist
//
//  Created by jcarlos on 15/2/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NFISimplePersistObject.h"

@interface User : NFISimplePersistObject <NFISimplePersistObjectProtocol>

@property (nonatomic, assign) NSInteger id;
@property (nonatomic, copy) NSString *user;
@property (nonatomic, copy) NSString *pass;

#pragma mark - Encode

- (void)encodeWithCoder:(NSCoder *)encoder;

#pragma mark - Init

- (instancetype)initWithId:(NSInteger)id user:(NSString *)user andPass:(NSString *)pass;

@end
