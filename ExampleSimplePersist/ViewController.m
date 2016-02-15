//
//  ViewController.m
//  ExampleSimplePersist
//
//  Created by José Carlos on 15/2/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import "ViewController.h"
#import "User.h"
#import "NFISimplePersist.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    User *user = [[User alloc] initWithId:1 user:@"Jose" andPass:@"asdasda"];
    [[NFISimplePersist standarSimplePersist] saveObject:user withKey:user.user];

}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    User *user = [[NFISimplePersist standarSimplePersist] loadFirstObject];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
