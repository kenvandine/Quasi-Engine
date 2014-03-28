
QuasiGame {
    id: game

    width: 800
    height: 600

    currentScene: scene
    property int initialPos: 1500

    QuasiScene {
        id: scene

        width: 2048
        height: 800

        Image {
            id: background
            source: "qrc:/background.png"
        }


        QuasiMaterial {
            id: myMaterial
            friction: 0.3
            density: 50
            restitution: 0.35
        }

        QuasiEntity {
             width: parent.width
             height: parent.height

             updateInterval: 50

             behavior: QuasiScriptBehavior {
                 script: {
                     /*
                     var yDiffTop = projectile.y - gameViewport.yOffset

                     // XXX use projectile velocity
                     if (Math.abs(yDiffTop) > 100)
                         gameViewport.vScroll(yDiffTop * 0.05)

                     var yDiffBot = projectile.y - (gameViewport.yOffset + gameViewport.height)

                     if (Math.abs(yDiffBot) > 100)
                         gameViewport.vScroll(yDiffBot * 0.05)

                     var xDiff = projectile.x - gameViewport.xOffset

                     if (Math.abs(xDiff) > 150)
                         gameViewport.hScroll(xDiff * 0.03)
                     */
                 }
             }
        }

        QuasiEntity {
            id: projectile
            x: 100
            y: 500
            width: trollface.width
            height: trollface.height

            sleepingAllowed: false
            bullet: true

            QuasiFixture {
                material: myMaterial
                shape: QuasiCircle {
                    anchors.fill: parent
                }
            }

            Image {
                id: trollface
                source: "qrc:/trollface.png"
            }
        }

        QuasiEntity {
            id: ground
            y: 750
            entityType: Quasi.StaticType
            sleepingAllowed: false

            width: scene.width
            height: 50

            QuasiFixture {
                material: myMaterial
                shape: Rectangle {
                    anchors.fill: parent
                    color: "brown"
                }
            }
        }

        QuasiEntity {
            id: wood01
            x: initialPos
            y: ground.y - height
            width: 15
            height: 110
            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: enemy01
            x: initialPos + wood01.width + 10
            y: ground.y - height
            width: enemy1.width
            height: enemy1.height

            sleepingAllowed: false

            QuasiFixture {
                material: myMaterial
                shape: QuasiCircle {
                    anchors.fill: parent
                }
            }

            Image {
                id: enemy1
                source: "qrc:/enemy.png"
            }
        }
        QuasiEntity {
            id: wood02

            x: initialPos + wood01.width + enemy01.width + 20
            y: ground.y - height
            width: 15
            height: 110

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: wood011

            x: initialPos + 55
            y: ground.y - (1.6 * height)
            width: 15
            height: 110
            rotation: 90

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: wood022

            x: initialPos + 175
            y: ground.y - (1.6 * height)
            width: 15
            height: 110
            rotation: 90

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: enemy02

            x: initialPos + wood01.width + enemy01.width + wood02.width + 30
            y: ground.y - height
            width: enemy2.width
            height: enemy2.height

            sleepingAllowed: false

            QuasiFixture {
                material: myMaterial
                shape: QuasiCircle {
                    anchors.fill: parent
                }
            }

            Image {
                id: enemy2
                source: "qrc:/enemy.png"
            }
        }
        QuasiEntity {
            id: wood03
            x: initialPos + wood01.width + enemy01.width + wood02.width + enemy02.width + 40
            y: ground.y - height
            width: 15
            height: 110

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: wood04
            x: initialPos + 60
            y: 500
            width: 15
            height: 110

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: wood044
            x: initialPos + 115
            y: 430
            width: 15
            height: 110
            rotation: 90

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: enemy03
            x: initialPos + wood04.width + 60
            y: ground.y - height - 300
            width: enemy3.width
            height: enemy3.height

            sleepingAllowed: false

            QuasiFixture {
                material: myMaterial
                shape: QuasiCircle {
                    anchors.fill: parent
                }
            }

            Image {
                id: enemy3
                source: "qrc:/enemy.png"
            }
        }
        QuasiEntity {
            id: wood05
            x: initialPos + wood04.width + enemy03.width + 70
            y: 500
            width: 15
            height: 110

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }

        // forever alone
        QuasiEntity {
            id: woodf
            x: initialPos + 400
            y: ground.y - height
            width: 15
            height: 110

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: enemyf
            x: initialPos + 400 + woodf.width + 10
            y: ground.y - height
            width: enemyfa.width
            height: enemyfa.height

            sleepingAllowed: false

            QuasiFixture {
                material: myMaterial
                shape: QuasiCircle {
                    anchors.fill: parent
                }
            }

            Image {
                id: enemyfa
                source: "qrc:/alone.png"
            }
        }
        QuasiEntity {
            id: woodf2
            x: initialPos + 400 + woodf.width + enemyf.width + 10
            y: ground.y - height
            width: 15
            height: 110

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
        QuasiEntity {
            id: woodff
            x: initialPos + 450
            y: ground.y - (1.6 * height)
            width: 15
            height: 110
            rotation: 90

            sleepingAllowed: false

            Image {
                source: "qrc:/wood.jpg"
                anchors.fill: parent
            }
        }
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            var xLaunch = 800 * (game.mouse.x - projectile.x);
            var yLaunch = 800 * (game.mouse.y - projectile.y);

            xLaunch = xLaunch > 150000 ? 150000 : xLaunch
            yLaunch = yLaunch < -150000 ? -150000 : yLaunch

            print (xLaunch, yLaunch)

            projectile.applyLinearImpulse(Qt.point(xLaunch, yLaunch),
                                          Qt.point(projectile.x + projectile.width / 2.0, projectile.y + projectile.height / 2.0)) // XXX expose b2pos
        }
    }
}
