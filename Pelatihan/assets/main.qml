// Default empty project template
import bb.cascades 1.0

// creates one page with a label

NavigationPane {
    id: navigationPane
    onPopTransitionEnded: {
        page.destoy()
    }
    Page {
        titleBar: TitleBar {
            id: title
            title: "Foto Hantu"
            visibility: ChromeVisibility.Visible
        }
        attachedObjects: [
            ComponentDefinition {
                id: detailPage
                source: "detailPage.qml"
            }
        ]
        Container {
            layout: StackLayout {
            }
            ListView {
                id: listdata
                objectName: "listdata"
                onTriggered: {
                    var data = dataModel.data(indexPath);
                    console.log(data.title + " " + data.url);
                    //  cs.updateStatus(data.text);
                    var page = detailPage.createObject()
                    page.setData(data.title, data.url);
                    // page.status = data.text
                    navigationPane.push(page)
                }
                listItemComponents: [
                    // The header displays a title along with a counter
                    ListItemComponent {
                        type: "item"
                        StandardListItem {
                            description: ListItemData.title
                        }
                    }
                ]
            }
        }
    }
}
