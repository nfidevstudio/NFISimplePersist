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
 *  Persist the object in the data base
 */
- (void)saveObject:(id)object withKey:(NSString *)key;

#pragma mark - Load methods

/**
 *  Load all objects in table
 */
- (NSArray *)loadAllObjects;

/**
 *  Load all objects in table with the same class
 */
- (NSArray *)loadAllObjectsWithClass:(Class)class;

/**
 *  Load the first object in the database. Return nil if the table is empty
 */
- (id)loadFirstObject;

/**
 *  Load the object with the given key in the database. Return nil if the table is empty
 */
- (id)loadObjectWithKey:(NSString *)key;


#pragma mark - Remove methods
/**
 *  Remove first object in the table. Return a BOOL with the result
 */
- (BOOL)removeFirstObject;

/**
 *  Remove object with the given key in the table. Return a BOOL with the result
 */
- (BOOL)removeObjectWithKey:(NSString *)key;

/**
 *  Remove object with the given class in the table. Return a BOOL with the result
 */
- (BOOL)removeObjectWithClass:(Class)class;

/**
 *  Remove all objects
 */
- (BOOL)removeAllObjects;

@end

