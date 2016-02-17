//
//  NFISimplePersist.h
//  ExampleSimplePersist
//
//  Created by José Carlos on 15/2/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NFISimplePersist : NSObject

#pragma mark - Instance.

/** Unique shared instance for NFISimplePersist.
 */
+ (instancetype)standarSimplePersist;

#pragma mark - Persist method

/**
 *  Persist the object
 */
- (void)saveObject:(id)object withKey:(NSString *)key;

#pragma mark - Load methods

/**
 *  Load all objects
 */
- (NSArray *)loadAllObjects;

/**
 *  Load all objects with the same class
 */
- (NSArray *)loadAllObjectsWithClass:(Class)class;

/**
 *  Load the object with the given key and class. Return nil if the table is empty
 */
- (id)loadObjectWithKey:(NSString *)key andClass:(Class)class;


#pragma mark - Remove methods

/**
 *  Remove object with the given key and class. Return a BOOL with the result
 */
- (BOOL)removeObjectWithKey:(NSString *)key andClass:(Class)class;

/**
 *  Remove object with the given class. Return a BOOL with the result
 */
- (BOOL)removeObjectsWithClass:(Class)class;

/**
 *  Remove all objects
 */
- (BOOL)removeAllObjects;

@end

