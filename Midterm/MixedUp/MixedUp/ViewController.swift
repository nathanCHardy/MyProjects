//
//  ViewController.swift
//  MixedUp
//
//  Created by Nathan Hardy on 10/12/16.
//  Copyright © 2016 Nathan Hardy. All rights reserved.
//

import UIKit
import GameplayKit

class ViewController: UIViewController {

    @IBOutlet weak var pic1: UIImageView!
    @IBOutlet weak var pic2: UIImageView!
    @IBOutlet weak var pic3: UIImageView!
    @IBOutlet weak var pic4: UIImageView!
    @IBOutlet weak var pic5: UIImageView!
    @IBOutlet weak var pic6: UIImageView!
    @IBOutlet weak var pic7: UIImageView!
    @IBOutlet weak var pic8: UIImageView!
    @IBOutlet weak var pic9: UIImageView!
    @IBOutlet weak var pic10: UIImageView!
    @IBOutlet weak var pic11: UIImageView!
    @IBOutlet weak var pic12: UIImageView!
    @IBOutlet weak var lblResult: UILabel!
    var isGameFinished = false
    var tapOne = 0
    var tapTwo = 0
    var tapAmount = 0
    var picArray = [UIImageView]()
    var normalArray = [Int](0...11)
    var shuffleArray = [Int]()
    var imageArray = [#imageLiteral(resourceName: "Image-1"), #imageLiteral(resourceName: "Image-2"), #imageLiteral(resourceName: "Image-3"), #imageLiteral(resourceName: "Image-4"), #imageLiteral(resourceName: "Image-5"), #imageLiteral(resourceName: "Image-6"), #imageLiteral(resourceName: "Image-7"), #imageLiteral(resourceName: "Image-8"), #imageLiteral(resourceName: "Image-9"),
                      #imageLiteral(resourceName: "Image-10"), #imageLiteral(resourceName: "Image-11"), #imageLiteral(resourceName: "Image-12")]
    override func viewDidLoad() {
        super.viewDidLoad()
        picArray.append(pic1);picArray.append(pic2);picArray.append(pic3);picArray.append(pic4);
        picArray.append(pic5);picArray.append(pic6);picArray.append(pic7);picArray.append(pic8);
        picArray.append(pic9); picArray.append(pic10);
        picArray.append(pic11);picArray.append(pic12);
        Shuffle()
        LoadImages()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

       func Shuffle() {
        shuffleArray = GKRandomSource.sharedRandom().arrayByShufflingObjects(in: normalArray) as! [Int]
    }
    func LoadImages() {
        for i in 0 ..< 12
        {
            picArray[i].image = imageArray[shuffleArray[i]]
        }
    }
    
    @IBAction func tap1(_ sender: UITapGestureRecognizer) {
        tapOne = 1
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 1
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap2(_ sender: UITapGestureRecognizer) {
        tapOne = 2
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 2
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap3(_ sender: UITapGestureRecognizer) {
        tapOne = 3
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 3
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap4(_ sender: UITapGestureRecognizer) {
        tapOne = 4
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 4
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap5(_ sender: UITapGestureRecognizer) {
        tapOne = 5
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 5
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap6(_ sender: UITapGestureRecognizer) {
        tapOne = 6
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 6
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap7(_ sender: UITapGestureRecognizer) {
        tapOne = 7
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 7
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap8(_ sender: UITapGestureRecognizer) {
        tapOne = 8
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 8
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap9(_ sender: UITapGestureRecognizer) {
        tapOne = 9
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 9
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap10(_ sender: UITapGestureRecognizer) {
        tapOne = 10
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 10
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap11(_ sender: UITapGestureRecognizer) {
        tapOne = 11
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 11
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func tap12(_ sender: UITapGestureRecognizer) {
        tapOne = 12
        tapAmount += 1
        if (tapAmount == 1)
        {
            tapTwo = 12
        }
        else if tapAmount == 2 {MovingPictures()}
        CheckForWinner()
    }
    @IBAction func returnMe(segue: UIStoryboardSegue)
    {
        lblResult.text = "Welcome back"
    }
    func CheckForWinner() {
        var picMatch = 0
        for i in 0 ..< 12
        {
            if picArray[i].image == imageArray[i]
            {
                picMatch += 1
            }
        }
        if picMatch == 12
        {
            lblResult.text = "Winner"
            isGameFinished = true
        }
        else
        {
            lblResult.text = "Keep Trying"
        }
    }
    func MovingPictures() {
       if !isGameFinished
       {
        var temp1: UIImage
        var temp2: UIImage
        temp1 = picArray[tapTwo - 1].image!
        temp2 = picArray[tapOne - 1].image!
        picArray[tapOne - 1].image = temp1
        picArray[tapTwo - 1].image = temp2
        tapAmount = 0
        }
    }
}

