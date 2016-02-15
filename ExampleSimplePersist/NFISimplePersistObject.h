//
//  NFSimplePersistObject.h
//  ExampleSimplePersist
//
//  Created by jcarlos on 15/2/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NFISimplePersistObjectProtocol <NSObject>

@required

/**
 *  Implement in model class. Return a dictionary (key - value) with the properties of the class.
 */
- (NSDictionary *)saveAsDictionary;

/**
 *  Implement in model class. Return the object given a dictionary.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface NFISimplePersistObject : NSObject

#pragma mark - Encode

- (void)encodeWithCoder:(NSCoder *)encoder andClass:(Class)objectClass;

- (id)initWithCoder:(NSCoder *)decoder andClass:(Class)objectClass;

@end
